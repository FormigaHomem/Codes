#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (long) 5e4 + 10

using namespace std;

typedef long l;

l N, visited[MAXN], parent[MAXN], level[MAXN], dist[MAXN], patriarch[MAXN], root;
vector<l> p[MAXN], g[MAXN];

void dfs(int v, int last, int height, int weight, int _patriarch){
    parent[v] = last;
    level[v] = height;
    dist[v] = weight;
    patriarch[v] = _patriarch;

    if(level[v] % root == 0)
        _patriarch = v;

    for(auto u : g[v])
        if(u != last)
            dfs(u, v, height + 1, weight + 1, _patriarch);
}

l lca(int u, int v){
    int U = u, V = v;

    while(patriarch[U] != patriarch[V]){
        if(level[U] > level[V]) U = patriarch[U];
        else V = patriarch[V];
    }

    while(U != V){
        if(level[U] >= level[V]) U = parent[U];
        else V = parent[V];
    }

    return dist[u] + dist[v] - 2 * dist[U];
}

int main(){

    cin >> N;

    root = sqrt(N) + 1;

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

    dfs(1, 1, 0, 0, 1);
    l ans = 0;

    for(int i = 1; i <= N / 2; i++)
        ans += lca(p[i][0], p[i][1]);
    cout << ans << endl;
}