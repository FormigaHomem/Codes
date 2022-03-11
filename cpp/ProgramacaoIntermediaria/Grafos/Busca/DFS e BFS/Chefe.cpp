#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 510
#define INF 0x3f3f3f3f

using namespace std;

long N, M, I, visited[MAXN], age[MAXN], original[MAXN], pos[MAXN], pos_original[MAXN], younger_boss_age[MAXN];
vector<int> bosses[MAXN];

long dfs(int v){
    visited[v] = 1;

    for(auto u : bosses[v])
        if(!visited[u]) younger_boss_age[v] = min(younger_boss_age[v], min(dfs(u), original[pos_original[u] ]) );
            
    return younger_boss_age[v];
}

int main(){_

    while(cin >> N >> M >> I){

        memset(younger_boss_age, INF, sizeof(younger_boss_age) );

        for(int i = 1; i <= N; i++){
            cin >> age[i];
            original[i] = age[i];
            pos[i] = pos_original[i] = i;
        }

        for(int i = 1; i <= M; i++){
            int u, v;

            cin >> u >> v;

            bosses[v].push_back(u);
        }

        while(I--){
            char task;
            int u, v;

            cin >> task >> u;

            if(task == 'T'){
                cin >> v;
                
                age[pos[v] ] = original[u];
                age[pos[u] ] = original[v];
                pos_original[pos[u] ] = v;
                pos_original[pos[v] ] = u;

                swap(pos[u], pos[v]);
            }

            else{
                if(dfs(pos[u]) != INF) cout << younger_boss_age[pos[u] ] << endl;
                else cout << "*\n";

                for(int i = 1; i <= N; i++){
                    visited[i] = 0;
                    younger_boss_age[i] = INF;
                }
            }
        }

        for(int i = 1; i <= N; i++) bosses[i].clear();
    }
}