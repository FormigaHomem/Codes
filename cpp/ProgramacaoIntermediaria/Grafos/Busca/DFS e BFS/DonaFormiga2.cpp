#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 2e2 + 10

using namespace std;

long S, T, P, h[MAXN], visited[MAXN];
vector<int> tunel[MAXN];

long bfs(){
    queue<int> q;
    q.push(P);
    long ans = 0;

    while(q.size() ){
        int v = q.front(); q.pop();

        visited[v] = 1;
        
        for(int u : tunel[v])
            if(!visited[u]){
                q.push(u);
                ans++;
                visited[u] = 1;
            }
    }

    return ans;
}

int main(){_

    cin >> S >> T >> P;

    for(int i = 1; i <= S; i++) cin >> h[i];

    for(int i = 1; i <= T; i++){
        int u, v;
        cin >> u >> v;

        if(h[u] > h[v]) tunel[u].push_back(v);
        else if(h[v] > h[u]) tunel[v].push_back(u);
    }

    cout << bfs() << endl;
}