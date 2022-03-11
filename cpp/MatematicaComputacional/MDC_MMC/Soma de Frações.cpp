#include <iostream>

using namespace std;

long int mdc(long int a, long int b){
    return (b? mdc(b, a % b) : a);
}

long int mmc(long int a, long int b){
    return (a * b) / mdc(a, b);
}

int main(){

    long int cima1, cima2, baixo1, baixo2;
    long int r1;

    cin >> cima1 >> baixo1 >> cima2 >> baixo2;

    if(baixo1 != baixo2){
        long  int a = baixo1, b = baixo2;
        baixo1 = mmc(baixo1, baixo2);
        cima1 *= (baixo1 / a);
        cima2 *= (baixo1 / b);
    }

    cout << (cima1 + cima2) / mdc(cima1 + cima2, baixo1) << " " << baixo1 / mdc(cima1 + cima2, baixo1);
}
