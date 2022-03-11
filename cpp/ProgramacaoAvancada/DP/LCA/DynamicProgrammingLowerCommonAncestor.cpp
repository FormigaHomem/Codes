#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (long) 5e4 + 10
#define LOG 20

using namespace std;

typedef long l;

l N, parent[MAXN][LOG], level[MAXN], dist[MAXN];
vector<l> p[MAXN], g[MAXN];

void dfs(int v, int last, int height, int weight){
    dist[v] = weight;
    level[v] = height;
    parent[v][0] = last;
    
    for(int i = 1; i < LOG; i++)
        if(parent[v][i - 1] != -1) parent[v][i] = parent[parent[v][i - 1] ][i - 1];
        
    for(auto u : g[v])
        if(u != last) dfs(u, v, height + 1, weight + 1);
}

l lca(int U, int V){
    int u = U, v = V;
    if(level[u] > level[v]) swap(v, u);

    for(int i = LOG - 1; i >= 0; i--)
        if(parent[v][i] != -1 and level[parent[v][i] ] >= level[u]) v = parent[v][i];
    
    if(v == u) return dist[U] + dist[V] - 2 * dist[v];

    for(int i = LOG - 1; i >= 0; i--)
        if(parent[v][i] != parent[u][i]) v = parent[v][i], u = parent[u][i];

    int _lca = parent[v][0];
    
    return dist[U] + dist[V] - 2 * dist[_lca]; 
}

int main(){_

    cin >> N;

    memset(parent, -1, sizeof(parent) );

    for(int i = 1; i <= N; i++){
        int x;
        cin >> x;
        p[x].push_back(i);
    }

    for(int i = 1; i < N; i++){
        int x, y;
        cin >> x >> y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1, 1, 0, 0);
    
    l ans = 0;

    for(int i = 1; i <= N / 2; i++)
        ans += lca(p[i][0], p[i][1]);
    cout << ans << endl;
}