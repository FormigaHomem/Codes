#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 101010
#define LOG 20
#define INF 0x3f3f3f3f
#define lsb(x) x & (-x)
#define f first
#define s second
#define endl "\n"

using namespace std;

typedef pair<long long, int> edge;

long N, Q, level[MAXN], parent[MAXN][LOG];
long long dist[MAXN];
vector<edge> adj[MAXN];

void dfs(int v, int p, int height, long long weight){
    dist[v] = weight;
    level[v] =  height;
    parent[v][0] = p;

    for(int i = 1; i < LOG; i++)
        if(parent[v][i - 1] != -1)
            parent[v][i] = parent[parent[v][i - 1] ][i - 1];
    for(auto u : adj[v])
        if(u.s != p) dfs(u.s, v, height + 1, weight + u.f);
}

int lca(int u, int v){
    if(level[u] > level[v]) swap(u, v);

    for(int i = LOG - 1; i >= 0; i--)
        if(parent[v][i] != -1 and level[parent[v][i] ] >= level[u]) v = parent[v][i];

    if(u == v) return v;

    for(int i = LOG - 1; i >= 0; i --)
        if(parent[v][i] != parent[u][i]) v = parent[v][i], u = parent[u][i];

    int _lca = parent[v][0];
    return _lca;
}

int main(){
    fastio

    while(cin >> N, N){

        memset(parent, -1, sizeof(parent) );

        for(int u = 1; u < N; u++){
            int v, w;
            cin >> v >> w;

            adj[u].emplace_back(w, v);
            adj[v].emplace_back(w, u);
        }

        dfs(0, -1, 0, 0);

        cin >> Q;

        while(Q--){
            int u, v;
            cin >> u >> v;
            cout << dist[u] + dist[v] - 2 * dist[lca(u, v) ];
            if(Q) cout << " ";
        }
        cout << endl;

        for(int i = 0; i < N; i++){
            adj[i].clear();
            dist[i] = level[i] = 0;
        }
    }
}