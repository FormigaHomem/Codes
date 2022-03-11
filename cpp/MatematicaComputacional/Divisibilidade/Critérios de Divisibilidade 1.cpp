#include <iostream>

using namespace std;

int main(){

    unsigned long long int soma = 0, ultimo;
    string a;

    cin >> a;

    for(char i : a) {
        ultimo = i - '0';
        soma += ultimo % 3;
        soma %= 3;
    }

    if(ultimo % 2 == 0) cout << "S\n";
    else cout << "N\n";

    if(soma % 3 == 0) cout << "S\n";
    else cout << "N\n";

    if(!ultimo or ultimo == 5) cout << "S\n";
    else cout << "N\n";

}
