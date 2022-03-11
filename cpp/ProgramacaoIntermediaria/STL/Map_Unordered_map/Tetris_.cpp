#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main(){_

    long N, t = 1;

    while(cin >> N, N){
        
        long pontos = 0, a, pont[15];
        map<long, set<string> > participante;
        string nome;

        while(N--){
            cin >> nome;
            for(int j = 1; j <= 12; j++){
                cin >> a;
                pontos += a;
                pont[j] = a;
            }
            pontos -= *max_element(pont + 1, pont + 13) + *min_element(pont + 1, pont + 13);
            participante[pontos].insert(nome);
            pontos = 0;
        }

        int index = 1, repeat = 0;
        cout << "Teste " << t++ << endl;
        for(auto it1 = participante.end(); true; it1--){
            if(it1 == participante.end() ) continue;
            for(auto it2 = it1->second.begin(); it2 != it1->second.end(); it2++) cout << index++ - repeat++ << " " << it1->first << " " << *it2 << endl;
            repeat = 0;
            if(it1 == participante.begin() ) break;
        }
        
    }
}