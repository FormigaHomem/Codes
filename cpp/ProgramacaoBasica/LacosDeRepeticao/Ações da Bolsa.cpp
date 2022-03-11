#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int N, m = -1000005, tam = 0;
    cin >> N;
    int Acoes[N], Valor[N];

    for(int i = 0; i < N; i++){
        cin >> Acoes[i];
        Valor[i] = 0;
    }

    for(int i = 0; i < N; i++){
        if(i + 4 <= N){
            for(int j = 0; j < 4; j++){
                //cout << Valor[i] << endl;
                Valor[i] += Acoes[i + j];
                //cout << Valor[i] << " " << Acoes[i + j] << endl << endl;
            }
            tam++;
            if(N == 4){
                tam++;
            }
        }
    }

    for(int i = 0; i < tam - 1; i++){
        m = max(Valor[i], max(Valor[i + 1], m) );
        //cout << Valor[i] << " " << Valor[i + 1] << " " << m << endl;
    }

    cout << m;

}
