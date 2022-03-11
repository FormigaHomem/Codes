#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e4 + 10

using namespace std;

long long int N, M, grau[MAXN];
vector<int> grafo[MAXN], lista;

int main(){_
    cin >> N >> M;

    for(int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        grau[v]++;
        grafo[u].push_back(v);
    }

    for(int i = 1; i <= N; i++)
       if(!grau[i]) lista.push_back(i);

    int ini = 0;
    while(ini < lista.size() ){

        int v = lista[ini++];

        for(int u : grafo[v]){
            grau[u]--;
            if(!grau[u]) {
                for(int j = ini; j <= lista.size(); j++) 
                    if(u < lista[j] or j == lista.size() ){
                        lista.insert(lista.begin() + j, u);
                        break;
                    }
            }
        }
    }

    if(lista.size() < N) cout << "Sandro fails.\n";
    else
        for(int i : lista) cout << i << " ";
}