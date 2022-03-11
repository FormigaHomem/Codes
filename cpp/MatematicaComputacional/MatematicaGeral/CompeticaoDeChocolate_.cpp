#include <iostream>

using namespace std;

int main(){

    int N, M, pos_perdedora;

    cin >> N >> M;

    pos_perdedora = M + 1;

    if(N % pos_perdedora == 0) cout << "Carlos\n";
    else cout << "Paula\n";
}