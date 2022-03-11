#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 2e2
#define pb push_back

using namespace std;

int N, M, U, V, P, Q, C, cor[MAXN];
vector<int> rua[MAXN];
bool visited[MAXN];

bool dfs(int v){
    
    if(v == Q) return true;
    visited[v] = true;

    for(int u : rua[v])
        if(!visited[u]){
            if(dfs(u) ){
                cor[u] = C;
                visited[u] = false;
                return true;
            }
            visited[u] = false;
        }

    return false;
}

int main(){

    cin >> N >> M;

    for(int i = 1; i < N; i++){
        cin >> U >> V;
        rua[U].pb(V);
        rua[V].pb(U);
    }

    for(int i = 1; i <= M; i++){
        cin >> P >> Q >> C;
        cor[P] = cor[Q] = C;
        dfs(P);
        visited[P] = false;
    }

    for(int i = 1; i <= N; i++) cout << cor[i] << " ";
}