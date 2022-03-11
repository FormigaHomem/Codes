#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e5 + 10

using namespace std;

int N, M, g, t = 1;
string u, v;

int main(){_

    while(cin >> N, N){

        unordered_map<string, int> grau;
        unordered_map<string, vector<string> > abigo;
        vector<string> lista;

        cin.ignore();
        getline(cin, u);

        for(int i = 1; i <= N; i++){
            cin >> u >> g;
            
            grau[u] = g;
            if(!g) lista.emplace(lista.begin(), u);
            
            while(g--){
                cin >> v;
                abigo[v].push_back(u);
            }
        }

        int ini = 0;
        while(ini < lista.size() ){
            string V = lista[ini++];

            for(auto U : abigo[V]){
                grau[U]--;
                if(!grau[U]) lista.push_back(U);
            }
        }

        cout << "Teste " << t++ << endl;
        if(lista.size() < N) cout << "impossivel\n\n";
        else{
            for(auto U : lista) cout << U << " ";
            cout << "\n\n";
        }
        
    }

}