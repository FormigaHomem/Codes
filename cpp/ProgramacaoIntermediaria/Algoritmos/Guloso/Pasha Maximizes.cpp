#include <iostream>

using namespace std;

int main(){
    int x = 0, y = 0, cont = 0, tam, k, maior, pos, temp, tempaux;
    string b;
    //Recebendo como string para poder lidar com os algarismos individualmente.
    cin >> b >> k;

    if(b.size() == 1 || k == 0){
        cout << b;
        return 0;
    }

    tam = b.size();
    int baux[tam + 5];
    //Criando um vetor de inteiros com cada algarismo do numero.
    for(int i = 0; i < tam; i++){
        baux[i] = b[i] - '0';
    }

    for(int i = 0; i < tam - 1; i++){

        maior = -1;
        //Executando um la�o lidando com os numeros a partir de depois de i (caso exista), at� o tamanho o ultimo elemento ou enquanto j <= a posi��o de i mais quantas trocas posso realizar, para assim lidar apenas com os numeros que vou realmente usar.
        for(int j = i + 1; j < tam && j <= i + k; j++){
            //Se o algarismo na posi��o j for maior que a variavel maior, maior passa a receber tal algarismo e pos recebe a posi��oem q esse algarismo est� dentro do numero.
            if(baux[j] > maior){
                maior = baux[j];
                pos = j;
            }
        }
        //Se a posi��o do algarismo em i for menor que o maior, vou trazer o maior at� essa posi��o com um algoritmo muito similar ao Bubble Sort, com alguma modifica��es.
        if(baux[i] < maior){
            int temp = baux[i];
            baux[i] = baux[pos];
            for(int j = i + 1; j <= pos; j++){
                int tempaux = baux[j];
                baux[j] = temp;
                temp = tempaux;
                k--;//Toda vez q tiver que fazer alguma modifica��o subtraio 1 de k.
            }
        }
        //Se eu j� tiver esgotado o meu limite de modifica��es, saio do la�o e imprimo o novo numero, o maior possivel com k modifica��es.
        if(k == 0) break;

    }

    for(int i = 0; i < tam; i++) cout << baux[i];

}
