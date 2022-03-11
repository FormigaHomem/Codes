#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){

    string a, divertido = ":-)", chateado = ":-(";
    int dv = 0, ch = 0;

    getline(cin, a);

    for(int i = 0; i < a.size() - 2; i++){
        string aux = a.substr(i, 3);
        if(aux == divertido) dv++;
        if(aux == chateado) ch++;
    }

    if(dv != ch){
        if(dv > ch) cout << "divertido";
        else cout << "chateado";
    }
    else cout << "neutro";

}
