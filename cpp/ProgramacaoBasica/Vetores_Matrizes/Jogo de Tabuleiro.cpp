#include <iostream>

using namespace std;

int main(){

    int N;

    cin >> N;

    int tabuleiro[N][N];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> tabuleiro[i][j];
        }
    }

    for(int i = 1; i < N; i++){
        for(int j = 1; j < N; j++){
            if( (tabuleiro[i][j - 1] + tabuleiro[i - 1][j] + tabuleiro[i - 1][j - 1]) == 2 || (tabuleiro[i][j - 1] + tabuleiro[i - 1][j] + tabuleiro[i - 1][j - 1]) == 3){
                tabuleiro[i][j] = 0;
            }
            else{
                tabuleiro[i][j] = 1;
            }
        }
    }

    cout << tabuleiro[N - 1][N - 1];



}
