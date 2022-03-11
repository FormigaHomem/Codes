#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 2e5 + 10

using namespace std;

long q, N, visited[MAXN], sz[MAXN], comp[MAXN], lig[MAXN], K;

int dfs(int v){
    if(sz[comp[v] ]) return sz[comp[v] ];
    comp[v] = K;
    sz[K]++;

    return dfs(lig[v]);

    return sz[K];
}

int main(){_

    cin >> q;

    while(q--){

        cin >> N;

        K = 1;

        for(int i = 1; i <= N; i++){
            cin >> lig[i];
            visited[i] = sz[i] = comp[i] = 0;
        }

        for(int i = 1; i <= N; i++){
            cout << dfs(i) << " ";
            K++;
        }
        cout << endl;

    }

}
