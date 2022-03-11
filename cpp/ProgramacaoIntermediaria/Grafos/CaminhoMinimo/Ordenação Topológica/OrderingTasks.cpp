#include <bits/stdc++.h>

#define MAXN (int) 1e2 + 10
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

long N, M;

int main(){_

    while(cin >> N >> M, N){

        int grau[MAXN] = {};
        vector<int> todo[MAXN] = {}, lista = {};

        for(int i = 1; i <= M; i++){
            int u, v;
            cin >> u >> v;
            todo[u].push_back(v);
            grau[v]++;
        }

        for(int i = 1; i <= N; i++)
            if(!grau[i]) lista.push_back(i);

        int ini = 0;
        while(ini < lista.size() ){
            int v = lista[ini++];

            for(int u : todo[v]){
                grau[u]--;
                if(!grau[u]) lista.push_back(u);
            }
        }

        for(int u : lista) cout << u << " ";
        cout << endl;
    }
}