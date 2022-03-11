#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 50

using namespace std;

long T, node, V, A, visited[MAXN], ans;
vector<int> graph[MAXN];

void dfs(int v){
    visited[v] = 1;

    ans++;
    for(int u : graph[v])
        if(!visited[u]) dfs(u);
    ans++;
}

int main(){_

    cin >> T;

    while(T--){
        cin >> node >> V >> A;

        for(int i = 1; i <= A; i++){
            int u, v;
            cin >> u >> v;

            visited[u] = visited[v] = 0;
            graph[u].push_back(v); graph[v].push_back(u);
        }

        dfs(node);
        cout << ans - 2 << endl;

        ans = 0;
    }

}