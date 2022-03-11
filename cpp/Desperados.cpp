//Código Luana

#include <bits/stdc++.h>
#define MAXN (int) 1e5 + 10
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

typedef pair<int, int> pii;

vector<int> grafo[MAXN], grafo2[MAXN], dag[MAXN];
pii arestas[MAXN];
long N, M, visited[MAXN], componente[MAXN], size[MAXN], grau[MAXN], K;
stack<int> pilha, debug_pilha;
queue<int> fila;

int top_sort(){
    long ans = 0;
    for (int i = 1; i <= K; i++)
        if (!grau[i] and size[i] <= 3) fila.push(i);
    
    while (!fila.empty()){
        int u = fila.front(); fila.pop();
        ans += size[u];
        for (int v : dag[u]){
            grau[v]--;
            if (!grau[v] and size[v] <= 3) fila.push(v);
        }
    }

    return ans;
} 

void dfs(int u){   
    visited[u] = 1;
    for (int v : grafo[u])
        if (!visited[v]) dfs(v);

    pilha.push(u);
    debug_pilha.push(u);
}

void dfs2(int u){
    componente[u] = K;
    size[K]++;
    visited[u] = 1;
    for (int v : grafo2[u])
        if (!visited[v]) dfs2(v);
}

int main() {_  

    cin >> N >> M;

    for (int i = 1; i <= M; i++){
        int a, b;
        cin >> a >> b;
        grafo2[b].push_back(a);
        grafo[a].push_back(b);
        arestas[i] = {a, b};
    }

    for (int i = 1; i <= N; i++)
        if (!visited[i] ) dfs(i);
    
    for(int i = 1; i <= N; i++) visited[i] = 0;

    while (!pilha.empty() ){
        int p = pilha.top(); pilha.pop();

        if (visited[p]) continue;

        K++;
        dfs2(p);
    }

    /*while(debug_pilha.size() ){
        int t = debug_pilha.top(); cout << t << " "; debug_pilha.pop();
    }
    cout << endl;
    for(int i = 1; i <= N; i++) cout << componente[i] << " ";
    cout << endl;
    for(int i = 1; i <= K; i++) cout << size[i] << " ";
    cout << endl;*/
 
    for (int i = 1; i <= M; i++)
        if (componente[arestas[i].first] != componente[arestas[i].second] ) {
            dag[componente[arestas[i].first] ].push_back(componente[arestas[i].second] );
            grau[componente[arestas[i].second] ]++;
        }

    cout << top_sort() << endl;
}