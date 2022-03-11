#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, P, X, Y, T;

    T = 0;

    cin >> N >> P;

    for(int contador = 0; contador < N; contador++){
        cin >> X >> Y;
        if(X + Y >= P){
            T++;
        }
    }

    cout << T;

}
