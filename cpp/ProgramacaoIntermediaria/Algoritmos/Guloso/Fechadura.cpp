#include <iostream>

using namespace std;

int main(){

    int N, M, x = 0;

    cin >> N >> M;

    int pinos[N + 5];

    for(int i = 0; i < N; i++){
        cin >> pinos[i];
    }

    for(int i = 0; i < N - 1; i++){
        if(pinos[i] == M) continue;
        while( (pinos[i] != M) || (pinos[i + 1] != M) ){
            if(pinos[i] < M){
                pinos[i]++;
                pinos[i + 1]++;
            }
            else{
                pinos[i]--;
                pinos[i + 1]--;
            }
            x++;
            if(pinos[i] == M || pinos[N - 1] == M) break;
        }
    }

    cout << x;

}
