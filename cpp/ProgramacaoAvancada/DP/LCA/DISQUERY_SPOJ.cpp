#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 101010
#define INF 0x3f3f3f3f
#define LOG 20
#define f first
#define s second
#define lsb(x) x & (-x)
#define endl "\n"

using namespace std;

typedef pair<long, long> pll;
typedef pair<int, pll> pill;
typedef pair<long, int> edge;

long N, Q, level[MAXN], minimum[MAXN][LOG], maximum[MAXN][LOG], parent[MAXN][LOG];
vector<edge> adj[MAXN];

void dfs(int v, int p, long height, long weight){
    level[v] = height;
    parent[v][0] = p;
    if(p != -1) minimum[v][0] = maximum[v][0] = weight;

    for(int i = 1; i < LOG; i++){
        if(parent[v][i - 1] != -1){
            parent[v][i] = parent[parent[v][i - 1] ][i - 1];
            if(parent[parent[v][i - 1]][i - 1] != -1){
                maximum[v][i] = max(maximum[v][i - 1], maximum[parent[v][i - 1] ][i - 1]);
                minimum[v][i] = min(minimum[v][i - 1], minimum[parent[v][i - 1] ][i - 1]);
            }
        }

    }
    for(auto u : adj[v])
        if(u.s != p) dfs(u.s, v, height + 1, u.f);
}

pll lca(int u, int v){
    long mini = INF, maxi = -1;
    if(level[u] > level[v]) swap(u, v);

    for(int i = LOG - 1; i >= 0; i--)
        if(parent[v][i] != -1 and level[parent[v][i] ] >= level[u]){
            maxi = max(maxi, maximum[v][i]);
            mini = min(mini, minimum[v][i]);
            v = parent[v][i];
        }

    if(u == v) return pll(mini, maxi);

    for(int i = LOG - 1; i >= 0; i--)
        if(parent[v][i] != parent[u][i]){
            maxi = max(maxi, max(maximum[v][i], maximum[u][i]) );
            mini = min(mini, min(minimum[v][i], minimum[u][i]) );
            v = parent[v][i], u = parent[u][i];
        }

    maxi = max(maxi, max(maximum[v][0], maximum[u][0]) );
    mini = min(mini, min(minimum[v][0], minimum[u][0]) );
    return pll(mini, maxi);
}

int main(){
    fastio

    cin >> N;

    memset(parent, -1, sizeof(parent) );
    memset(minimum, INF, sizeof(minimum) );
    memset(maximum, -1, sizeof(maximum) );

    for(int i = 1; i < N; i++){
        long u, v, w;
        cin >> u >> v >> w;

        adj[u].emplace_back(w, v);
        adj[v].emplace_back(w, u);
    }

    dfs(1, -1, 0, -1);

    cin >> Q;

    while(Q--){
        int u, v;
        cin >> u >> v;

        pll ans = lca(u, v);
        cout << ans.f << " " << ans.s << endl;
    }
}