#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 101010

using namespace std;

long N, M, team[MAXN];
vector<long> friends[MAXN];

bool isBipartite(int v){
    queue<int> q;
    q.push(v);

    team[v] = 0;
    bool ok = 1;

    while(!q.empty() and ok){
        v = q.front(); q.pop();

        for(auto u : friends[v]){
            if(team[u] == -1){
                team[u] = not team[v];
                q.push(u);
            }
            else if(team[u] == team[v]) ok = 0;
        }
    }

    return ok;
}

int main(){

    cin >> N >> M;

    for(int i = 1; i <= M; i++){
        int u, v;
        cin >> u >> v;

        friends[u].push_back(v);
        friends[v].push_back(u);
    }

    bool ok = 1;
    memset(team, -1, sizeof(team) );
    
    for(int i = 1; i <= N; i++)
        if(team[i] == -1) ok &= isBipartite(i);

    if(ok){
        for(int i = 1; i <= N; i++) cout << team[i] + 1 << " ";
    }

    else cout << "IMPOSSIBLE\n";
}