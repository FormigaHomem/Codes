#include <iostream>
#include <vector>
#include <queue>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e5 + 10

using namespace std;

int N, azuis = 0, vermelhas = 1, u, v;
vector<int> rua[MAXN];
bool visited[MAXN], cor[MAXN];

/*void dfs(int v){
    visited[v] = true;

    for(int i : rua[v]){
        if(!visited[i]){
            cor[i] = !cor[v];
            (cor[i])? azuis++ : vermelhas++;
            dfs(i);
        }
    }

}*/

void bfs(){

    queue<int> q;
    q.push(1);

    while(!q.empty() ){
        int v = q.front();
        q.pop();
        visited[v] = true;

        for(int u : rua[v]){
            if(!visited[u]){
                q.push(u);
                cor[u] = !cor[v];
                (cor[u])? azuis++ : vermelhas++;
            }
        }
    }
    if(azuis == vermelhas) cout << "Y\n";
    else cout << "N\n";

}

int main(){_

    cin >> N;

    for(int i = 1; i < N; i++){
        cin >> u >> v;
        rua[u].push_back(v);
        rua[v].push_back(u);
    }

    /*dfs(1);
    cout << (azuis == vermelhas? "Y\n" : "N\n");*/

    bfs();
}
