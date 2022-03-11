#include <iostream>

using namespace std;

int main(){

    int N, cont = 0, beira, comeco, fim;
    bool c, f;


    cin >> N;

    int piscina[N + 10];

    for(int i = 0; i < N; i++) cin >> piscina[i];

    comeco = piscina[0];
    fim = piscina[N - 1];

    for(int i = 0; i < N; i++){
        if(piscina[i] != comeco){
            if(piscina[i] > comeco) c = 1;
            else c = 0;
            break;
        }
    }

    for(int i = N - 1; i >= 0; i--){
        if(piscina[i] != fim){
            if(piscina[i] > fim) f = 1;
            else f = 0;
            break;
        }
    }

    if(c) cont++;
    if(f) cont++;

    for(int i = 1; i < N - 1; i++){
        if(piscina[i - 1]  > piscina[i]) beira = piscina[i];
        if(piscina[i + 1] > piscina[i] or piscina[i] == beira or (c and piscina[i] == comeco) or (f and piscina[i] == fim) ) cont++;
    }

    cout << cont;

}
