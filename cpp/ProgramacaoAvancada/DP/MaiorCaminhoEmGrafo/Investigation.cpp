#include <bits/stdc++.h>
 
#define MAXN (ll) 1e5 + 10
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define f first
#define s second
#define MOD (ll) 1e9 + 7
 
using namespace std;
 
typedef pair<long long, int> pli;
typedef long long ll;
 
ll N, M, dp[MAXN], dist[MAXN], min_arestas[MAXN];
vector<pli> flight[MAXN];
 
ll Dijkstra(){
    dist[1] = min_arestas[1] = 0;
    priority_queue<pli, vector<pli>, greater<pli> > fila;
    fila.push( {0, 1} );
 
    while(fila.size() ){
        ll u = fila.top().s, D = fila.top().f;
        fila.pop();
 
        if(D > dist[u]) continue;
 
        for(pli atual : flight[u]){
            long v = atual.s, d = atual.f;
            
            if(dist[v] > D + d){  
                min_arestas[v] = min_arestas[u] + 1;
                dist[v] = D + d;
                fila.push( {dist[v], v} );
            }

            if(dist[v] == D + d) min_arestas[v] = min(min_arestas[v], min_arestas[u] + 1);
        }
    }
 
    return dist[N];
}
 
ll ways(int id, ll price){
    if(id > N) return 0;
    if(id == N) return 1;
 
    if(dp[id] != -1) return dp[id];
 
    ll resp = 0;
 
    for(pli u : flight[id]){
        if(price + u.f <= dist[u.s]){
            resp += ways(u.s, price + u.f); 
            resp %= MOD;
        }
    }
 
    return dp[id] = resp;
}
 
ll longest_way(int id, ll price){
    if(id >= N) return 0;
 
    if(dp[id] != -1) return dp[id];
 
    ll resp = 0;
 
    for(pli u : flight[id])
        if(price + u.f <= dist[u.s]) resp = max(resp, 1 + longest_way(u.s, price + u.f) );
 
    if(resp == 0) return -MAXN;
 
    return dp[id] = resp;
}
 
int main(){_
 
    cin >> N >> M;
 
    for(int i = 1; i <= M; i++){
        int u, v, w;
        cin >> u >> v >> w;
 
        flight[u].push_back( {w, v} );
        dist[u] = dist[v] = min_arestas[u] = min_arestas[v] = (ll) 1e15;
        dp[u] = dp[v] = -1;
    }
 
    cout << Dijkstra() << " " << ways(1, 0) << " " << min_arestas[N] << " ";
    memset(dp, -1, sizeof(dp) );
    cout << longest_way(1, 0) << endl;
}