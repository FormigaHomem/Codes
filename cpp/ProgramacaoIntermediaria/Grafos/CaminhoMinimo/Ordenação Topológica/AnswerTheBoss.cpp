#include <bits/stdc++.h>

#define MAXN (int) 1e3 + 10
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

long T, N, R, t = 1;

int main(){_

    cin >> T;

    while(T--){

        cin >> N >> R;

        map<int, set<int> > rank;
        vector<int> lower[MAXN], lista;
        int grau[MAXN] = {}, Rank[MAXN] = {};

        for(int i = 1; i <= R; i++){
            int u, v;
            cin >> u >> v;
            lower[v].push_back(u);
            grau[u]++;
        }

        for(int i = 0; i < N; i++)
            if(!grau[i]){
                lista.push_back(i);
                rank[1].insert(i);
                Rank[i] = 1;
            }

        int ini = 0;

        while(ini < lista.size() ){
            int v = lista[ini++];

            for(int u : lower[v]){
                grau[u]--;
                if(!grau[u]){
                    lista.push_back(u);
                    if(!Rank[u]){
                        Rank[u] = Rank[v] + 1;
                        rank[Rank[u] ].insert(u);
                    }
                    
                    else if(Rank[u] < Rank[v] + 1){
                        rank[Rank[u] ].erase(u);
                        Rank[u] = Rank[v] + 1;
                        rank[Rank[u] ].insert(u);
                    }
                }
            }
        }

        cout << "Scenario #" << t++ << ":\n";
        for(pair<int, set<int> > v : rank)
            for(int u : v.second) cout << v.first << " " << u << endl;
            
        if(T) cout << endl;
    }
}