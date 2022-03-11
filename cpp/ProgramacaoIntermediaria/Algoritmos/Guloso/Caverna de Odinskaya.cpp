#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int N, M;
    long int soma = 0;

    cin >> N >> M;

    int mergulhos[N + 5];

    for(int i = 0; i < N; i++){
        cin >> mergulhos[i];
    }

    mergulhos[0] = min(mergulhos[0], M - mergulhos[0]);
    soma = mergulhos[0];

    for(int i = 1; i < N; i++){
            mergulhos[i] = min(mergulhos[i], M - mergulhos[i]);
            if(mergulhos[i] < mergulhos[i - 1]) mergulhos[i] = M - mergulhos[i];
            if(mergulhos[i] < mergulhos[i - 1]){
                cout << -1;
                return 0;
            }
            soma += mergulhos[i];
    }

    cout << soma;

}
