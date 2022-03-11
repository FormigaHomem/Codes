#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e7 + 10

using namespace std;

long N, M, dist[MAXN], longest_path[MAXN];
vector<int> flight[MAXN];

long long bfs(){
    dist[1] = 1;
    queue<int> fila;
    fila.push(1);

    while(!fila.empty() ){
        int v = fila.front();
        fila.pop();

        for(int u : flight[v])
            if(dist[v] + 1 > dist[u]){
                dist[u] = dist[v] + 1;
                longest_path[u] = v;
                fila.push(u);
            }
    }
    return dist[N];
}

void backtracking(int v){_
    
    if(v != 1) backtracking(longest_path[v]);
    cout << v << " ";
}

int main(){_

    cin >> N >> M;

    for(int i = 1; i <= M; i++){
        int a, b;
        cin >> a >> b;
        flight[a].push_back(b);
        dist[a] = dist[b] = -1;
    }

    long ans = bfs();
    if(ans == -1) cout << "IMPOSSIBLE\n";
    else{
        cout << ans << endl;
        backtracking(N);
    }
}