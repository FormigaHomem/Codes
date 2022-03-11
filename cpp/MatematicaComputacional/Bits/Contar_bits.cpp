#include <iostream>

using namespace std;

typedef unsigned long long ull;

int count1(ull x){
    int cont = 0;
    while(x){
        cont++;
        x -= x & -x;
    }
    return cont;
}

int main(){
    ull N, aux;

    cin >> N;

    cout << count1(N);
}
