#include <iostream>

using namespace std;

int main(){

    string a;

    cin >> a;

    int tam = a.size(), b[26] = {0}, cont = 0;

    for(int i = 0; i < tam; i++) b[a[i] - 97]++;

    for(int i = 0; i < 26; i++)
        if(b[i] % 2) cont++;

    if(cont % 2 || cont <= 1) cout << "First";
    else cout << "Second";

}
