#include <bits/stdc++.h>
using namespace std;
int main(){

    int N, M, X, f = 0;

    int album[105];

    cin >> N;

    cin >> M;

    for(int i = 1; i <= N; i++){
        album[i] = 0;
    }

    for(int i = 0; i < M; i++){
        cin >> X;
        album[X] = 1;
    }

    for(int i = 1; i <= N; i++){
        if(album[i] == 0){
            f++;
        }
    }

    cout << f;

}
