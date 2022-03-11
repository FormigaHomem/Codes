var verify = window.document.querySelector("input.subm")
var data = new Date
var year = data.getFullYear()

verify.onclick = function (){
    var birthYear = window.document.querySelector("input")
    var age = year - Number(birthYear.value)
    var gender = window.document.querySelectorAll('[name="gender"]')
    var userCommunication = window.document.querySelector("div#image")
    var img = window.document.createElement("img")

    if(birthYear.value == null || birthYear.value < year - 100 || birthYear.value > year){
        window.alert(`Digite um ano válido! O ano mínimo é ${year - 100} e o ano máximo é ${year}`)
        
        if(userCommunication.hasChildNodes() ) userCommunication.innerHTML = "Detectamos "

        return null
    }

    
    userCommunication.style.textAlign= "center"
    img = answerQuery(userCommunication, age, img, gender)
    
    if(userCommunication.childElementCount) userCommunication.replaceChild(img, userCommunication.firstElementChild)
    else userCommunication.appendChild(img)
}

function answerQuery(userCommunication, age, img, gender){
    
    if(gender[0].checked){
        
        if(age <= 4){
            img.src= "bebeM.jpg"
            userCommunication.innerHTML = `Detectamos um bebê de ${age} ${age > 1? "anos" : "ano"}!`
        }

        else if(age <= 12){
            img.src= "criançaM.jpg"
            userCommunication.innerHTML = `Detectamos uma criança de ${age} anos!`    
        }

        else if(age <= 17){
            img.src= "adolescenteM.jpg"
            userCommunication.innerHTML = `Detectamos um adolescente de ${age} anos!`
        }

        else if(age <= 24){
            img.src= "jovemM.jpg"
            userCommunication.innerHTML = `Detectamos um jovem de ${age} anos!`
        }
        
        else if(age <= 59){
            img.src= "adultoM.jpg"
            userCommunication.innerHTML = `Detectamos um adulto de ${age} anos!`
        }
        
        else if(age <= 99){
            img.src= "idosoM.jpg"
            userCommunication.innerHTML = `Detectamos um idoso de ${age} anos!`
        }

        else if(age == 100){
            img.src= "infinito.jpg"
            userCommunication.innerHTML = `Detectamos um imortal de ${age} anos!`
        }
    }

    else{

        if(age <= 4){
            img.src= "bebeF.jpg"
            userCommunication.innerHTML = `Detectamos uma bebê de ${age} ${age > 1? "anos" : "ano"}!`
        }
        
        else if(age <= 12){
            img.src= "criançaF.jpg"
            userCommunication.innerHTML = `Detectamos uma criança de ${age} anos!` 
        }
        
        else if(age <= 17){
            img.src= "adolescenteF.jpg"
            userCommunication.innerHTML = `Detectamos uma adolescente de ${age} anos!`
        }
        
        else if(age <= 24){
            img.src= "jovemF.jpg"
            userCommunication.innerHTML = `Detectamos uma jovem de ${age} anos!`
        }
        
        else if(age <= 59){
            img.src= "adultaF.jpg"
            userCommunication.innerHTML = `Detectamos uma adulta de ${age} anos!`
        }
        
        else if(age <= 99){
            img.src= "idosaF.jpg"
            userCommunication.innerHTML = `Detectamos uma idosa de ${age} anos!`
        }
        
        else if(age == 100){
            img.src= "infinito.jpg"
            userCommunication.innerHTML = `Detectamos uma imortal de ${age} anos!`
        }
    }

    return img
}