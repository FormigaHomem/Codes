#include <iostream>
#include <cmath>

using namespace std;

int main(){

    long long int L, cont = 1;

    cin >> L;

    while(L >= 2){
        L /= 2;
        cont *= 4;
    }
    cout << cont;
}
