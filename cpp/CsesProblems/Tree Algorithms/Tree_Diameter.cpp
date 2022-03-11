#include <bits/stdc++.h>
 
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 2e5 + 10
 
using namespace std;
 
long N, D, last_vertex, dist[MAXN];
vector<long> nodes[MAXN];
 
void dfs(int v, int last){
    dist[v] = dist[last] + 1;
 
    if(dist[v] > D){
        D = dist[v];
        last_vertex = v;
    }
 
    for(int u : nodes[v])
        if(u != last) dfs(u, v);
}
 
int main(){_
 
    cin >> N;
 
    for(int i = 1; i < N; i++){
        int u, v;
        cin >> u >> v;
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }
 
    dfs(1, 1);
 
    for(int i = 1; i <= N; i++) dist[i] = 0;
 
    dfs(last_vertex, last_vertex);
 
    cout << --D << endl;
}
