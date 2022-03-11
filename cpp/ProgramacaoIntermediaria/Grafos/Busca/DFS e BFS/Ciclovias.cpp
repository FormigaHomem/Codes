#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e5 + 10

using namespace std;

long N, M, u, v, ini;
vector<int> roads[MAXN], path[MAXN];

long dfs(int v, int sz){

    long ans = sz;

    for(int u : roads[v])
        
        if(u > path[ini][ (int) path[ini].size() - 2] ){
            path[ini].push_back(u);
            ans = max(ans, dfs(u, sz + 1) );
            path[ini].pop_back();
        } 

    return ans;
}

int main(){_

    cin >> N >> M;

    for(int i = 1; i <= M; i++){
        cin >> u >> v;
        roads[u].push_back(v);
        roads[v].push_back(u);
        if(path[u].empty() ){
            path[u].push_back(0); path[u].push_back(0); path[u].push_back(u);
        }

        if(path[v].empty() ){
            path[v].push_back(0); path[v].push_back(0); path[v].push_back(v);
        }
    }

    for(int i = 1; i <= N; i++){
        ini = i;
        
        cout << dfs(i, 1) << " ";
    }
}