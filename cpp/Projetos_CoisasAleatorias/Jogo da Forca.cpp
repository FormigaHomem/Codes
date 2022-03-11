#include <iostream>
#include <string>

using namespace std;

string Try, no_changes, tries, spacement1 = "\t\t\t\t\t\t", spacement2 = "\t\t\t\t", secret_word, show, game_design = " \t __________\n\t|          |\n\t|          |\n\t|          \n\t|          \n\t|         \n"; //game_design forma a forca.
char parts[6] = {'O', '|', '/', '\\', '/', '\\'}; char op;//head - 'O', body - '|', left_arm - '/', right_arm - '\\'.
int tam, x = 0, wrong_ones = 0, right_ones = 0, parts_position[6] = {54, 68, 67, 69, 83, 85};
bool gotcha = false;

void restart_variables(){
    Try = ""; no_changes = ""; tries = ""; spacement1 = "\t\t\t\t\t\t"; spacement2 = "\t\t\t\t"; secret_word = ""; show = ""; game_design = " \t __________\n\t|          |\n\t|          |\n\t|           \n\t|             \n\t|          \n"; //game_design forma a forca.
    op = ' ';//head - 'O', body - '|', left_arm - '/', right_arm - '\\'.
    tam = 0; x = 0; wrong_ones = 0; right_ones = 0;
    gotcha = false;
}

void inicial_message(){
    cout << endl << spacement1 << "Jogo da Forca!\n\n" << spacement2 << "Digite a palavra secreta que você desafiará a pessoa.\n" << spacement1 << "   ";//Mensagem padrão.
    cin >> secret_word;//Pega qual é a palavra secreta.
    tam = secret_word.size();
}

void design_stuff(){
    cout << endl << spacement1 << "Jogo da Forca!\n\n" << game_design << "\t ";//Mensagem padrão.
    for(int i = 0; i < tam; i++) show[i] = (show[i] == '_' and secret_word[i] == '!'? no_changes[i]  : show[i]);//Preenche a mensagem que será mostrada ao usuário.
    cout << show << endl << "\tTentativas falhas: ";
    for(char i : tries) cout << i << " ";
    cout << endl << spacement1 << "Faça a sua tentativa!\n" << spacement1;//Mensagem padrão.
}

bool word_checkup(char upper, char lower, string Try){
    if(Try.size() > 1) {//Se o usuário digitar mais de uma letra peço para que ele digite apenas uma letra.
        cout << spacement1 << "Digite apenas uma letra!";
        for(long int i = 0; i < 2050000000; i++);//Um tempo para o usúario ler a mensagem.
        system("cls");
        cout << endl << spacement1 << "Jogo da Forca!\n\n" << game_design << "\t " << show << endl << "\tTentativas falhas: ";
        for(char i : tries) cout << i << " ";
        cout << endl << spacement1;
        return true;
    }
    if(tries.find(upper) != string::npos or tries.find(lower) != string::npos) {//Se o usuário já tiver tentado esta letra pede para digitar outra letra.
        cout << "\t\t\tVocê já tentou essa letra anteriormente, por favor digite outra letra!";
        for(long int i = 0; i < 2050000000; i++);//Um tempo para o usúario ler a mensagem.
        system("cls");
        cout << endl << spacement1 << "Jogo da Forca!\n\n" << game_design << "\t " << show << endl << "\tTentativas falhas: ";
        for(char i : tries) cout << i << " ";
        cout << endl << spacement1;
        return true;
    }

    return false;
}

void game(char upper, char lower){
    while(secret_word.find(upper) != string::npos or secret_word.find(lower) != string::npos){//Enquanto achar a letra digitada ou em minúsculo ou em maiúsculo.
        int a = (secret_word.find(upper) != string::npos? secret_word.find(upper) : secret_word.find(lower) );//Marco a posição onde foi encontrada essa letra.
        secret_word[a] = '!';//Marco essa posição para depois mostrar para o usuário quais letras ele já acertou.
        right_ones++;//Digo que ele acertou mais uma letra.
        gotcha = true;//E que ele acertou essa tentativa.
    }

    if(!gotcha){//Caso ele não tenha acertado.
        tries += tolower(Try[0]);//Adiciono na lista de tentativas falhas.
        game_design[parts_position[x] ] = parts[x]; x++;//Adiciono uma parte do boneco.
        wrong_ones++;//E digo que o usuário errou sua tentativa.
    }
}

bool endgame_stuff(){
    cout << spacement1 << "A palavra secreta era " << no_changes << "!\n";
    if(wrong_ones == 6) cout << spacement2 << "     Que pena, você perdeu! Mais sorte na próxima!\n";
    else cout << spacement1 << "    Parabéns! Você venceu!\n";
    cout << spacement2 << "\t     Que tal tentar mais uma vez? S/N?";

    cin >> op;

    system("cls");
    if(op == 'S' or op == 's') return true;

    system("cls");
    cout << spacement2 << "\t   A gente se vê na próxima!\n";
    for(long int i = 0; i < 1000000000; i++);
    system("cls");
    return false;
}

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    reiniciar:
    restart_variables();

    inicial_message();

    no_changes = secret_word;

    show.insert(0, tam, '_');//Preenche a string com '_'.

    system("cls");//Limpa a tela.
    while(wrong_ones < 6 and right_ones < tam){

        design_stuff();

        new_try:
        cin >> Try;//Tentativa do usuario.
        char upper = toupper(Try[0]), lower = tolower(Try[0]);//Pega a letra digitada em maiúsculo e minúsculo.

        if(word_checkup(upper, lower, Try) ) goto new_try;//Caso o usuário tenha digitado uma letra repetida ou mais de uma letra peço para que digite novamente.

        gotcha = false;

        game(upper, lower);//Faço as marcações de onde tem a letra que o usuário acertou, caso tenha acertado, se errou excluo uma parte do boneco.

        system("cls");
    }
    if(endgame_stuff() ) goto reiniciar;// Digo qual era a palavra secreta e se o usuário perdeu ou ganhou. Depois pergunto se quer jogar mais uma rodada, se sim reinicia o código, senão imprimo uma mensagem de despedida e encerro o programa.
}
