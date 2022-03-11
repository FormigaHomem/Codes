#include <bits/stdc++.h>
 
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (long long) 1e5 + 10
#define INF 0x3f3f3f3f
 
using namespace std;
 
long long N, M;
vector<long long> connection[MAXN], dist, route, visited;
 
void bfs(){
    route.assign(N + 5, 0); visited.assign(N + 5, 0);
    queue<long long> q;
    q.push(1);
    dist[1] = 0;
 
    while(!q.empty() ){
        long long v = q.front();
        q.pop();
        visited[v] = 1;
 
        for(auto u : connection[v])
            if(!visited[u]){
                if(dist[v] + 1 < dist[u]){
                    dist[u] = dist[v] + 1;
                    route[u] = v;
                }
 
                q.push(u);
            }
    }
}
 
void backtracking(long long v){_
 
    if(v == 1){
        cout << 1 << " ";
        return;
    }
 
    backtracking(route[v]);
    cout << v << " ";
}
 
int main(){_
 
    cin >> N >> M;
    
    dist.assign(N + 5, 0); 
 
    for(int i = 1; i <= M; i++){
        long long u, v;
        cin >> u >> v;
        dist[u] = dist[v] = INF;
 
        connection[u].push_back(v);
        connection[v].push_back(u);
    }
 
    bfs();
 
    if(dist[N] == INF) cout << "IMPOSSIBLE\n";
    else{
        cout << dist[N] + 1 << "\n";
        backtracking(N);
    }
}