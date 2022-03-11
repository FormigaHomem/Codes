#include<bits/stdc++.h>
#include<unordered_set>

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 101010
#define INF 0x3f3f3f3f
#define LOG 20
#define f first
#define s second
#define lsb(x) x & (-x)
#define endl "\n"

using namespace std;

int N, M, level[MAXN], parent[MAXN][LOG];
string kidsToy[MAXN];
unordered_set<string> toys[MAXN][LOG];
vector<int> adj[MAXN];

void dfs(int v, int p, int height, string toy){
    level[v] = height;
    parent[v][0] = p;
    
    if(p != -1) toys[v][0].insert(toy);

    for(int i = 1; i < LOG; i++)
        if(parent[v][i - 1] != -1){
            parent[v][i] = parent[parent[v][i - 1] ][i - 1];
            if(parent[parent[v][i - 1] ][i - 1] != -1){
                auto it1 = toys[v][i - 1], it2 = toys[parent[v][i - 1] ][i - 1]; 
                for(auto it = it1.begin(); it != it1.end(); it++) toys[v][i].insert(*it);
                for(auto it = it2.begin(); it != it2.end(); it++) toys[v][i].insert(*it);
            }
        }

    for(auto u : adj[v])
        if(u != p) dfs(u, v, height + 1, kidsToy[u]);
}

int lca(int u, int v){
    unordered_set<string> ans;
    if(level[u] > level[v]) swap(u, v);

    for(int i = LOG - 1; i >= 0; i--)
        if(parent[v][i] != -1 and level[parent[v][i] ] >= level[u]){
            auto it1 = toys[v][i]; 
            for(auto it = it1.begin(); it != it1.end(); it++) ans.insert(*it);
            v = parent[v][i];
        }

    if(u == v){
        ans.insert(kidsToy[v]);
        return ans.size();
    }

    for(int i = LOG - 1; i >= 0; i--)
        if(parent[v][i] != parent[u][i]){
            auto it1 = toys[v][i], it2 = toys[u][i];
            for(auto it = it1.begin(); it != it1.end(); it++) ans.insert(*it);
            for(auto it = it2.begin(); it != it2.end(); it++) ans.insert(*it);
            v = parent[v][i], u = parent[u][i];
        }

    ans.insert(*toys[v][0].begin() );
    ans.insert(*toys[u][0].begin() );
    ans.insert(kidsToy[parent[v][0] ]);
    return ans.size();
}

int main(){
    fastio

    cin >> N >> M;

    memset(parent, -1, sizeof(parent) );

    for(int i = 1; i <= N; i++) cin >> kidsToy[i];

    for(int i = 1; i < N; i++){
        int u, v;
        cin >> u >> v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, -1, 0, "a");

    while(M--){
        int u, v;
        cin >> u >> v;

        cout << lca(u, v) << endl;
    }
}