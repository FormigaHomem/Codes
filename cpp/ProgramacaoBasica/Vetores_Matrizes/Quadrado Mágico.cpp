#include <bits/stdc++.h>
using namespace std;
int main(){

    int N = 3, soma, l = 0, c = 0, d1 = 0, d2 = 0;

    int cubo[11][11];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> cubo[i][j];
            l += cubo[i][j];
        }
        if(i == 0){
            soma = l;
        }
        if(l != soma){
            soma = -1;
        }
        d1 += cubo[i][i];
        d2 += cubo[i][(N - 1) - i];

        if( (i == N - 1) && (d1 != soma || d2 != soma) ){
            soma = -1;
        }
        l = 0;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            c += cubo[j][i];
        }

        if(soma == -1){
            break;
        }

        if(c != soma){
            soma = -1;
            break;
        }
        if(i < N - 1){
            c = 0;
        }
    }


    cout << (soma == -1? "NAO" : "SIM");

}
