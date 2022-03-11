#include <bits/stdc++.h>

#define MAXN (long) 1e4 + 10

using namespace std;

int N, Fita[MAXN];

int main(){

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> Fita[i];
        if(Fita[i] == -1) Fita[i] = 10;
    }

    for(int i = 1; i < N; i++) Fita[i] = min( {Fita[i], Fita[i - 1] + 1, 9} );
        
    for(int i = N - 2; i >= 0; i--) Fita[i] = min( {Fita[i], Fita[i + 1] + 1, 9} );

    for(int i = 0; i < N; i++) cout << Fita[i];
}
