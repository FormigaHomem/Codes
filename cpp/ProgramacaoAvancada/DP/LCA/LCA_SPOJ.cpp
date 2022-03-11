#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 1010
#define LOG 20

using namespace std;


long T, t, N, M, Q, level[MAXN], dist[MAXN], parent[MAXN][LOG];
vector<int> adj[MAXN];

void dfs(int v, int p, int h, int w){
    level[v] = h;
    dist[v] = w;
    parent[v][0] = p;

    for(int i = 1; i < LOG; i++)
        if(parent[v][i - 1] != -1)
            parent[v][i] = parent[parent[v][i - 1] ][i - 1];

    for(auto u : adj[v])
        if(u != p) dfs(u, v, h + 1, w + 1);
}

int lca(int u, int v){
    if(level[u] > level[v]) swap(u, v);

    for(int i = LOG - 1; i >= 0; i--)
        if(parent[v][i] != -1 and level[parent[v][i]] >= level[u]) v = parent[v][i];
    
    if(u == v) return v;

    for(int i = LOG - 1; i >= 0; i--)
        if(parent[v][i] != parent[u][i]) v = parent[v][i], u = parent[u][i];

    int _lca = parent[v][0];
    return _lca;
}

int main(){_

    cin >> T;

    while(T--){
        cin >> N;
        for(int i = 1; i <= N; i++){
            cin >> M;
            while(M--){
                int x;
                cin >> x;
                adj[i].push_back(x);
                adj[x].push_back(i);
            }
        }

        memset(parent, -1, sizeof(parent) );
        dfs(1, -1, 0, 0);

        cin >> Q;

        cout << "Case " << ++t << ":\n";
        while(Q--){
            int u, v;
            cin >> u >> v;
            cout << lca(u, v) << endl;
        }
    }
}