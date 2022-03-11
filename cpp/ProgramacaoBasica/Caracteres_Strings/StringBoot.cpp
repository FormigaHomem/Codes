#include <bits/stdc++.h>

using namespace std;

int main(){
    string nome1, nome2, secret_word; 
    int desloc; 

    cin >> nome1 >> nome2;

    if(nome1 != "Reluew" or nome2 != "Markinhos"){
        cout << "Nao eh possivel descriptografar!";
        return 0;
    }

    cin >> desloc >> secret_word;

    for(char i : secret_word) cout << i + 6;
}