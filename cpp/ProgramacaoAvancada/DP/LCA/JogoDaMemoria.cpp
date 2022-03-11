#include<bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 50101
#define LOG 20
#define f first
#define s second

using namespace std;

long N, ans, dist[MAXN], level[MAXN], parent[MAXN][LOG];
pair<int, int> c[MAXN];
vector<int> graph[MAXN];

void dfs(int v, int p, int height, int weight){
    dist[v] = weight;
    level[v] = height;
    parent[v][0] = p;

    for(int i = 1; i < LOG; i++)
        if(parent[v][i - 1] != -1)
            parent[v][i] = parent[parent[v][i - 1] ][i - 1];

    for(auto u : graph[v])
        if(u != p) dfs(u, v, height + 1, weight + 1);
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

    cin >> N;

    memset(parent, -1, sizeof(parent) );

    for(int i = 1; i <= N; i++){
        int x;
        cin >> x;
        if(c[x].first) c[x].second = i;
        else c[x].first = i;
    }

    for(int i = 1; i < N; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, -1, 0, 0);

    for(int i = 1; i <= N / 2; i++) ans += dist[c[i].f] + dist[c[i].s] - 2 * dist[lca(c[i].f, c[i].s) ];

    cout << ans << endl;
}