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
        //Executando um laço lidando com os numeros a partir de depois de i (caso exista), até o tamanho o ultimo elemento ou enquanto j <= a posição de i mais quantas trocas posso realizar, para assim lidar apenas com os numeros que vou realmente usar.
        for(int j = i + 1; j < tam && j <= i + k; j++){
            //Se o algarismo na posição j for maior que a variavel maior, maior passa a receber tal algarismo e pos recebe a posiçãoem q esse algarismo está dentro do numero.
            if(baux[j] > maior){
                maior = baux[j];
                pos = j;
            }
        }
        //Se a posição do algarismo em i for menor que o maior, vou trazer o maior até essa posição com um algoritmo muito similar ao Bubble Sort, com alguma modificações.
        if(baux[i] < maior){
            int temp = baux[i];
            baux[i] = baux[pos];
            for(int j = i + 1; j <= pos; j++){
                int tempaux = baux[j];
                baux[j] = temp;
                temp = tempaux;
                k--;//Toda vez q tiver que fazer alguma modificação subtraio 1 de k.
            }
        }
        //Se eu já tiver esgotado o meu limite de modificações, saio do laço e imprimo o novo numero, o maior possivel com k modificações.
        if(k == 0) break;

    }

    for(int i = 0; i < tam; i++) cout << baux[i];

}
