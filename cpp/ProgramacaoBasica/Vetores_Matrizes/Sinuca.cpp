#include <iostream>

using namespace std;

int main(){

    int N;

    cin >> N;

    int Sinuca[N + 5][N + 5];

    for(int i = 0; i < N; i++) cin >> Sinuca[0][i];

    for(int i = 1; i < N; i++)
        for(int j = 0; j < N - i; j++) Sinuca[i][j] = (Sinuca[i - 1][j] == Sinuca[i - 1][j + 1])? 1 : -1;

    (Sinuca[N - 1][0] == 1)? cout << "preta" : cout << "branca";

}
