#include <iostream>

using namespace std;

typedef unsigned long long ull;

int main(){

    ull N, aux;

    cin >> N;

    while( (N & 1) and N != 1) {
        aux = N;
        N >>= 1;
    }

    if( (N & 1) ) cout << 'S';
    else cout << 'N';
}
