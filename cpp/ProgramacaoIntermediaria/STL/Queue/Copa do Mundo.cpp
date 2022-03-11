#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main(){

    queue<char> time;
    int a, b;

    for(int i = 0; i < 15; i++){
        cin >> a >> b;
        if(i <= 7){//Se forem as oitavas
            time.push('A' + 2 * i);// Coloca na fila a letra correspondente do primeiro competidor.
            if(a < b) time.back() = ('A' + 2 * i + 1);//Caso o vencedor seja o segundo competidor, substituo a letra que foi colocada no final da fila.
        }
        else{
            //Se não forem mais as oitavas.
            if(a < b) {//Vejo se o b ganhou, caso seja verdade.
                time.pop();//Tiro a letra correspondente ao a da fila.
                time.push(time.front() );//Coloco no final da fila a letra correspondente ao competidor b.
                time.pop();//E tiro essa mesma letra do inicio da fila.
            }
            else{//Caso o a tenha vencido.
                time.push(time.front() );//Coloco no final da fila a letra correspondente ao competidor a.
                time.pop();//Tiro a letra correspondente ao a da fila.
                time.pop();//E tiro a letra correspondente ao b do inicio fila.
            }
            //Repetindo esse processo coloco no final da fila o vencedor e tiro do inicio ambos os competidores, diminuindo então, a fila até que sobre apenas o vencedor do campeonato.
        }
    }

    cout << time.front();//Printo o único que sobrou da fila, o vencedor do campeonato.
}
