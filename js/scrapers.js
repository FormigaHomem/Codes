const puppeteer = require('puppeteer');

async function scrape(url, login, senha){    

    // stage 1: setup for scraping and getting login and password inputs

    // unic phase
    const browser = await puppeteer.launch();
    const [page] = await browser.pages();
    await page.goto(url, {waiUntil: ['load', 'domcontentloaded'] } );
    const domain = "https://cses.fi";
    const nickname = await page.$("input[name='nick']");
    const password = await page.$("input[name='pass']");
    var Codes = new Map(); 
    var CodeProperties = new Object();

    
    // stage 2: making the login and going to the problemset page

    // phase 1: typing the login
    await Promise.all( [
        await nickname.focus(),
        await nickname.type(login, {delay: 250} ),
        await nickname.dispose()
    ] );
    
    // phase 2: typing the password
    await Promise.all( [
        await password.focus(),
        await password.type(senha, {delay: 250} ),
        await password.dispose(),
    ] );

    // phase 3: clicking the submit button
    await Promise.all( [
        await page.click("input[type='submit']", {delay: 1000} ),
        await page.waitForNavigation( {waitUntil: ['load', 'domcontentloaded'] } ),
        await page.goto(`${domain}/problemset`, {waiUntil: ['load', 'domcontentloaded'] } )
    ] );


    // stage 3: get the categorizations and the links to all problems at least tried
    
    // phase 1: setup
    const uls = Array.from(await page.$$('ul.task-list') ); 
    var anchors = new Array();
    var CategoryOf = new Map();

    // phase 2: getting the links and categorizing the problems 
    for(let i = 1; i < uls.length; i++){
        let ulNodes = await page.evaluate( (el) => el.childNodes.length, uls[i]);
        let category_name = await page.$eval(`body > div.skeleton > div.content-wrapper > div > h2:nth-child(${2 * i + 2})`, el => el.textContent);
            
        for(let j = 1; j <= ulNodes; j++){
                let anchor = await page.$(`body > div.skeleton > div.content-wrapper > div > ul:nth-child(${2 * i + 3}) > li:nth-child(${j}) > a`);
                let done = await page.$(`body > div.skeleton > div.content-wrapper > div > ul:nth-child(${2 * i + 3} ) > li:nth-child(${j}) > span.task-score.icon.full`);
                let tried = await page.$(`body > div.skeleton > div.content-wrapper > div > ul:nth-child(${2 * i + 3}) > li:nth-child(${j}) > span.task-score.icon.zero`);
                let link = await page.evaluate( (el) => el.getAttribute('href'), anchor);
                let problem_name = await page.evaluate( (el) => el.textContent.replace(" ", "_"), anchor);

                if(done != undefined || tried != undefined){
                    anchors.push(link);
                    CategoryOf.set(problem_name, category_name);
                }
            }
        }


    // stage 4: visit the problems' page and get the links to the last submition page, where the last code submitted for the problem is located

    var submitions = new Array();

    // unic phase
    for(let anchor of anchors){
            await Promise.all( [
                await page.goto(domain+anchor, {waitUntil: ['load', 'domcontentloaded'] } ),
            ] );

            submitions.push(await page.$eval("body > div.skeleton > div.content-wrapper > div.nav.sidebar > a:nth-child(12)", (el) => {
                return el.getAttribute('href');
            } ) );
    }


    // stage 5: finally, visit the submissions' page, assemble the lines' code into one string and organize the codes.

    var CodesProperties = new Array();
    for(let submition of submitions){

        await Promise.all( [ 
            await page.goto(domain+submition, {waitUnitl: ['load', 'domcontentloaded'] } )
        ] )

        // phase 1: get the code
        let code = await page.evaluate( () => {
            let code = "";
            let code_lines = Array.from(document.querySelectorAll("body > div.skeleton > div.content-wrapper > div.content > div:nth-child(4) > div > pre > div > div") );
            for(let line of code_lines){
                for(let useless_stuff of line.childNodes){
                    code += useless_stuff.textContent;
                }
                code += "\n";
            }

            return code;
        } );

        // phase 2: get the problem's name and category
        let problem_name =  await page.evaluate( () => document.querySelector("body > div.skeleton > div.content-wrapper > div.content > title").textContent.split(" - ")[1].replace(" ", "_"));
        let problem_category = CategoryOf.get(problem_name);
        let problem_id = await page.evaluate( () => document.querySelector("body > div.skeleton > div.content-wrapper > div.content > table.summary-table.left-align.narrow > tbody > tr:nth-child(1) > td:nth-child(2) > a").getAttribute('href').split("/")[3] );
        
        // phase 3: pack the code's data into the Code object and the codes of the same category into the Codes map
        CodeProperties = {problemName: problem_name, code: code, problemId: problem_id};
        if(CodesProperties.length > 0){
            var last_code_name = CodesProperties[CodesProperties.length - 1].problemName;
        }

        if(CodesProperties.length == 0 || CategoryOf.get(last_code_name) == problem_category){
            CodesProperties.push(CodeProperties);
        }

        else{
            
            Codes.set(CategoryOf.get(last_code_name), CodesProperties);
            CodesProperties = [CodeProperties];
        }
    }

    if(CodesProperties.length > 0){
        Codes.set(CategoryOf.get(CodeProperties.problemName), CodesProperties);
    }

    console.log("Scraping finished!");
    page.close();
    browser.close();
    return [Codes, CategoryOf];
}
 
function build(Codes, path){
    // stage 1: setup and create the main directory

    const fs = require("fs");
    const dir = path+"\\CsesProblems";

    // unic phase:
    fs.mkdir(dir, (err) => {
        if(err){
            fs.rmdir(dir, (err) => {
                if(err){
                    return console.log("Something went wrong when we tried to delete the main directory", err);
                }
                console.log("The main directory was deleted due to some issue when trying to build it", err);
            } );
        }
        console.log("The main directory was built succesfully!");
    } );
    

    // stage 2: create the categories directories and codes' files
    for(let [Category, Arr] of Codes.entries() ){

        // phase 1: create the category directory
        fs.mkdir(dir+`\\${Category}`, (err) => {
            if(err){
                return console.log("Something went wrong when we tried to create a directory.", Category, err);
            }
        } );

        for(let Code of Arr){

            // phase 2: create the code's file
            fs.writeFile(dir+`\\${Category}\\${Code.problemName+".cpp"}`, Code.code, (err) => {
                if(err){
                    return console.log("There was some issue on trying to create the file", Code.problemName, err);
                }
            } );
        }
    }

    console.log("Your directory was built succesfully!");
}

async function ScrapeAndBuild(answer){
    // stage 1: setup and scrape the cses to get the necessaries infos

    // unic phase
    var login = answer.option2; var password = answer.option3; path = answer.option4;
    console.log("Drink a coffee while we build your directory");
    var info = await scrape("https://cses.fi/login", login, password).catch( (err) => {
        return console.log("Something went wrong when we tried to get your codes! Check your login and password and try again.", err);
    } );


    // stage 2: use the info to build the cses problems directory

    // unic phase
    Codes = info[0]; CategoryOf = info[1];
    build(Codes, path);

    return [Codes, CategoryOf];
}

function UpdateCode(answer, CategoryOf, path){
    const fs = require('fs');
    const open = require('open');

    
    // stage 1: setup and check the file's state

    // phase 1: setup
    var problem_name = answer.option2;
    var problem_category = CategoryOf.get(problem_name);
    var filePath = `${path}\\CsesProblems\\${problem_category}\\${problem_name}.cpp`;

    // phase 2: check if the file is in the expected spot
    fs.stat(filePath, (err) => {
        if(err){
            return console.log("Check the file's path and try again. The path should be", filePath, err);
        }
        console.log("Problem's file found succesfully!");
    } );


    // stage 2: open the file -> not working :/

    /* unic phase
    first try
    fs.open(filePath, 'w+', (err, fd) => {
        if(err){
            return console.log("Something went wrong when we tried to open your code! Check the file's path and try again. The path should be", filePath, err);
        }
        console.log("File opened succesfully!", fd);
    } );
    second try
    open(filePath, {wait: true, app:'C:\\Users\\caueh_syddo7g\\AppData\\Local\\Microsoft VS Code\\_\\Code.exe'} );*/
}

async function DeleteDirectory(path, Codes){

    // stage 1: setup, check the file's state and delete the files

    // phase 1: setup and check the if the file is in the supposed spot
    const fs = require('fs');
    const dir = path+"\\CsesProblems";

    fs.stat(dir, (err) => {
        if(err){
            return console.log("Check your directory and try again! Its path should be:", dir);
        }
    } );

    // phase 2: delete the files
    for(let [Category, Arr] of Codes.entries() ){
        for(let Code of Arr){
            fs.rm(dir+`\\${Category}\\${Code.problemName}.cpp`, (err) => {
                if(err){
                    return console.log("Something went wrong when we tried to delete a file.", err);
                }
            } );
        }
    }


    // stage 2: delete the main and secondaries directories

    // unic phase
    fs.rmdir(dir, {recursive: true}, (err) => {
        if(err){
            return console.log("Something went wrong when we tried to delete your directory.", err);
        }
        console.log("Your directory was deleted succesfully :(");
    } );
}

async function main(path, CategoryOf, Codes){
    const inquirer = require('inquirer');

    // first question
    await inquirer.prompt( [ 
        {   name: "option1", 
            type: "list",
            message: "What would you like?", 
            choices: ["To create your Cses problems directory?", "To update a code?", "To delete your Cses problems directory?"],
        }, ] ).then( async function(answer){
    
        if(answer.option1 == "To create your Cses problems directory?"){
        
            // login, password and path questions
            await inquirer.prompt( [ 
                {   name: "option2",
                    type: "input",
                    message: "Type your cses.fi login",
                },
                {   name: "option3",
                    type: "password",
                    mask: "*",
                    message: "Type your cses.fi password",

                },
                {   name: "option4",
                    type: "input",
                    message: "Type the path where you would like your Cses problems directory to be",
                },   
                    // literraly what the name says
            ] ).then( async function(answer) {
                path = answer.option4;
                let info = await ScrapeAndBuild(answer);
                Codes = await info[0]; CategoryOf = await info[1];
            } ).catch( (err) => console.log(err) );
        }

        else if(answer.option1 == "To update a code?"){

            // code's name question
            await inquirer.prompt( [ 
                {   name: "option2",
                    type: "input",
                    message: "Type the problem's name you would like to update the code",
                }   
            ] ).then( (answer) => UpdateCode(answer, CategoryOf, path) ).catch( (err) => console.log(err) );
        }

        else if(answer.option1 == "To delete your Cses problems directory?"){
            DeleteDirectory(path, Codes);
        }
    
    } ).catch( (err) => console.log(err) ) 

    // recursion
    main(path, CategoryOf, Codes).catch( (err) => console.log(err) );
}

main('', new Map(), new Map() ).catch( (err) => console.log(err) );