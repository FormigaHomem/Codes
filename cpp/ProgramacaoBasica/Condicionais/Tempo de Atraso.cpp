#include <iostream>

using namespace std;

int main(){

    int a, b, c, d, dif;

    cin >> a >> b >> c >> d;

    a = a * 60 + b + 45;
    b = c * 60 + d;

    (a <= b)? cout << "Sucesso" : cout << "Atrasado " << a - b;

}
