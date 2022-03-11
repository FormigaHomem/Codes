#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (long) 5e4 + 10

using namespace std;

typedef long l;

l N, visited[MAXN], parent[MAXN], level[MAXN], dist[MAXN];
vector<l> p[MAXN], g[MAXN];

void dfs(int v, int last, int height, int weight){
    parent[v] = last;
    level[v] = height;
    dist[v] = weight;

    for(auto u : g[v])
        if(u != last)
            dfs(u, v, height + 1, weight + 1);
}

l lca(int u, int v){
    int U = u, V = v;
    while(level[U] != level[V]){
        if(level[U] > level[V]) U = parent[U];
        if(level[V] > level[U]) V = parent[V];
    }

    while(U != V){
        U = parent[U];
        V = parent[V];
    }

    return dist[u] + dist[v] - 2 * dist[U];
}

int main(){

    cin >> N;

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