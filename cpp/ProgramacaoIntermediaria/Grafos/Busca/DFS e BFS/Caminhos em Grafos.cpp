#include <iostream>
#include <vector>
#include <queue>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e5

using namespace std;

int V, P, v1, v2;
vector<int> vizinhos[MAXN];
bool visited[MAXN], chega;

/*void dfs(int v){
    if(v == v1) chega = true;
    visited[v] = true;


    for(int i : vizinhos[v])
        if(!visited[i]) dfs(i);
}*/

bool bfs(int ini){
    queue<int> q;
    q.push(ini);
    while(!q.empty() ){
        int v = q.front();
        if(v == v2) return true;
        q.pop();
        visited[v] = true;

        for(int i : vizinhos[v])
            if(!visited[i]) q.push(i);
    }
    return false;
}

int main(){_

    cin >> V >> P;

    for(int i = 0; i < P; i++){
        cin >> v1 >> v2;

        vizinhos[v1].push_back(v2);
        vizinhos[v2].push_back(v1);
    }

    cin >> v1 >> v2;

    //dfs(v2);
    if(bfs(v1) ) cout << "EXISTE\n";
    else cout << "NAO EXISTE\n";
}
