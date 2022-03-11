#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 10101
#define f first
#define s second

using namespace std;

long N, M;
vector<int> g[MAXN];

bool isBipartite(int v, long N){
    queue<int> q;
    long partition[MAXN];
    bool ok = 1;
    memset(partition, -1, sizeof(partition) );

    partition[v] = 0;
    q.push(v);

    while(!q.empty() and ok){
        v = q.front(); q.pop();

        for(auto u : g[v]){
            if(partition[u] == -1){
                partition[u] = 1 + partition[v];
                q.push(u);
            }

            else if(partition[u] == partition[v]) ok = false;
        }
    }

    return ok;
}

int main(){

    cin >> N >> M;

    for(int i = 1; i <= M; i++){
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    cout << "O grafo " << (isBipartite? "é" : "não é") << "bipartido.\n";

}