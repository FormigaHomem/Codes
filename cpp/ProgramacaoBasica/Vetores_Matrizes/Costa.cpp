#include <iostream>

using namespace std;

int main(){

    int M, N, costa = 0;

    cin >> M >> N;

    char mapa[M + 5][N + 5];

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++) cin >> mapa[i][j];
    }

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(mapa[i][j] == '#' and ( (mapa[i][j + 1] == '.' or j == N - 1) or (mapa[i][j - 1] == '.' or j == 0) or (mapa[i + 1][j] == '.' or i == M - 1) or (mapa[i - 1][j] == '.' or i == 0) ) ) costa++;
        }
    }

    cout << costa;

}
