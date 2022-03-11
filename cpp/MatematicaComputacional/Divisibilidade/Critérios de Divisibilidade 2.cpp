#include <iostream>

using namespace std;

int main(){

    unsigned long long int soma = 0, alg;
    string a, ultimos = "";

    cin >> a;

    for(int i = 0; i < a.size(); i++) {
        if(i + 1 == a.size() or i + 2 == a.size() ) ultimos += a[i];
        soma += (a[i] - '0') % 9;
        soma %= 9;
    }

    alg = stoi(ultimos);

    if(alg % 4 == 0) cout << "S\n";
    else cout << "N\n";

    if(soma % 9 == 0) cout << "S\n";
    else cout << "N\n";

    if(alg % 25 == 0) cout << "S\n";
    else cout << "N\n";

}
