#include <bits/stdc++.h>
using namespace std;
int main(){

    int N, l = 0, c = 0, d1 = 0, d2 = 0, M;

    cin >> N;

    int X[N][N];
    int L[N];
    int C[N];
    int D1[N];
    int D2[N];
    int *Soma[N][N];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> X[i][j];
            if(X[i][j] == 0){
                X[i][j] = 1;
            }
            else{
                X[i][j] = 0;
            }
            Soma[i][j] = &X[i][j];
            l += X[i][j];
        }
        L[i] = l;
        l = 0;
        D1[i] = X[i][i];
        d1 += D1[i];
        D2[i] = X[i][(N - 1) - i];
        d2 += D2[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            c += X[j][i];
        }
        C[i] = c;
        c = 0;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(Soma[i][j] == Soma[i][j]){
                *Soma[i][j] = L[i] - 1;
            }

            if(Soma[i][j] == Soma[j][i]){
                *Soma[i][j] += C[j] - 1;
            }

            if(Soma[i][j] == Soma[i][i]){
                *Soma[i][j] += d1 - 1;
            }

            if(Soma[i][j] == Soma[i][(N - 1) - i]){
                *Soma[i][j] += d2 - 1;
            }
           if(j > 0|| i > 0){
                M = max(*Soma[i][j], *Soma[i][j - 1]);
           }
            //cout << L[i] << " " << C[j] << " " << d1 << " " << d2 << " " << *Soma[i][j] << " ";
        }
        //cout << endl;
    }


    cout << M;

}
