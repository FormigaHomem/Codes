#include <iostream>

using namespace std;

int main(){
    int N, M, d = 0;

    cin >> N >> M;

    int v[N + 10];

    for(int i = 0; i < N; i++) cin >> v[i];
    if(42195 - v[N - 1] > M){
        cout << 'N';
        return 0;
    }
    for(int i = N - 1; i > 0; i--)
        if(v[i] - v[i - 1] > M){
            cout << 'N';
            return 0;
        }

    cout << 'S';

}
