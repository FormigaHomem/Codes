#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> Flavinho(6), Loteria(6);
    int acertos = 0;
    string premio[6] = {"azar", "azar", "terno", "quadra", "quina", "sena"};

    for(auto i = Flavinho.begin(); i != Flavinho.end(); i++) cin >> *i;
    for(auto i = Loteria.begin(); i != Loteria.end(); i++){
        cin >> *i;
    }

    for(int i = 0; i < 6; i++){
        auto a = find(Loteria.begin(), Loteria.end(), Flavinho[i]);
        if(a != Loteria.end() ) acertos++;
    }
    if(!acertos) acertos++;
    cout << premio[acertos - 1];

}
