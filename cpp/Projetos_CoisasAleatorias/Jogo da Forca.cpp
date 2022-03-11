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
    cout << endl << spacement1 << "Jogo da Forca!\n\n" << spacement2 << "Digite a palavra secreta que voc� desafiar� a pessoa.\n" << spacement1 << "   ";//Mensagem padr�o.
    cin >> secret_word;//Pega qual � a palavra secreta.
    tam = secret_word.size();
}

void design_stuff(){
    cout << endl << spacement1 << "Jogo da Forca!\n\n" << game_design << "\t ";//Mensagem padr�o.
    for(int i = 0; i < tam; i++) show[i] = (show[i] == '_' and secret_word[i] == '!'? no_changes[i]  : show[i]);//Preenche a mensagem que ser� mostrada ao usu�rio.
    cout << show << endl << "\tTentativas falhas: ";
    for(char i : tries) cout << i << " ";
    cout << endl << spacement1 << "Fa�a a sua tentativa!\n" << spacement1;//Mensagem padr�o.
}

bool word_checkup(char upper, char lower, string Try){
    if(Try.size() > 1) {//Se o usu�rio digitar mais de uma letra pe�o para que ele digite apenas uma letra.
        cout << spacement1 << "Digite apenas uma letra!";
        for(long int i = 0; i < 2050000000; i++);//Um tempo para o us�ario ler a mensagem.
        system("cls");
        cout << endl << spacement1 << "Jogo da Forca!\n\n" << game_design << "\t " << show << endl << "\tTentativas falhas: ";
        for(char i : tries) cout << i << " ";
        cout << endl << spacement1;
        return true;
    }
    if(tries.find(upper) != string::npos or tries.find(lower) != string::npos) {//Se o usu�rio j� tiver tentado esta letra pede para digitar outra letra.
        cout << "\t\t\tVoc� j� tentou essa letra anteriormente, por favor digite outra letra!";
        for(long int i = 0; i < 2050000000; i++);//Um tempo para o us�ario ler a mensagem.
        system("cls");
        cout << endl << spacement1 << "Jogo da Forca!\n\n" << game_design << "\t " << show << endl << "\tTentativas falhas: ";
        for(char i : tries) cout << i << " ";
        cout << endl << spacement1;
        return true;
    }

    return false;
}

void game(char upper, char lower){
    while(secret_word.find(upper) != string::npos or secret_word.find(lower) != string::npos){//Enquanto achar a letra digitada ou em min�sculo ou em mai�sculo.
        int a = (secret_word.find(upper) != string::npos? secret_word.find(upper) : secret_word.find(lower) );//Marco a posi��o onde foi encontrada essa letra.
        secret_word[a] = '!';//Marco essa posi��o para depois mostrar para o usu�rio quais letras ele j� acertou.
        right_ones++;//Digo que ele acertou mais uma letra.
        gotcha = true;//E que ele acertou essa tentativa.
    }

    if(!gotcha){//Caso ele n�o tenha acertado.
        tries += tolower(Try[0]);//Adiciono na lista de tentativas falhas.
        game_design[parts_position[x] ] = parts[x]; x++;//Adiciono uma parte do boneco.
        wrong_ones++;//E digo que o usu�rio errou sua tentativa.
    }
}

bool endgame_stuff(){
    cout << spacement1 << "A palavra secreta era " << no_changes << "!\n";
    if(wrong_ones == 6) cout << spacement2 << "     Que pena, voc� perdeu! Mais sorte na pr�xima!\n";
    else cout << spacement1 << "    Parab�ns! Voc� venceu!\n";
    cout << spacement2 << "\t     Que tal tentar mais uma vez? S/N?";

    cin >> op;

    system("cls");
    if(op == 'S' or op == 's') return true;

    system("cls");
    cout << spacement2 << "\t   A gente se v� na pr�xima!\n";
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
        char upper = toupper(Try[0]), lower = tolower(Try[0]);//Pega a letra digitada em mai�sculo e min�sculo.

        if(word_checkup(upper, lower, Try) ) goto new_try;//Caso o usu�rio tenha digitado uma letra repetida ou mais de uma letra pe�o para que digite novamente.

        gotcha = false;

        game(upper, lower);//Fa�o as marca��es de onde tem a letra que o usu�rio acertou, caso tenha acertado, se errou excluo uma parte do boneco.

        system("cls");
    }
    if(endgame_stuff() ) goto reiniciar;// Digo qual era a palavra secreta e se o usu�rio perdeu ou ganhou. Depois pergunto se quer jogar mais uma rodada, se sim reinicia o c�digo, sen�o imprimo uma mensagem de despedida e encerro o programa.
}
