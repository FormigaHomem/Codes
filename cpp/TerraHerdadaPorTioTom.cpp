#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 110

using namespace std;

long N, M, K, gr[MAXN][MAXN], visited[MAXN], match[MAXN];
vector<long> graph[MAXN];

int augmenting(int v){
    if(visited[v]) return 0;

    visited[v] = 1;

    for(auto u : graph[v]){
        if(!visited[u] and (match[u] == -1 or augmenting(u) ) ){
            match[u] = v; 
            return 1;
        }
    }
    
    return 0;
}

int main(){

    while(cin >> N >> M, N){
        cin >> K;

        memset(gr, -1, sizeof(gr) );

        for(int i = 1; i <= K; i++){
            int x, y;
            cin >> x >> y;

            gr[x][y] = 0;
        }

        long cont = 1;

        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= M; j++)
                if(gr[i][j] == -1) gr[i][j] = cont++;
            
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= M; j++)
                if(gr[i][j] > 0){
                    if(gr[i - 1][j] > 0){
                        graph[gr[i][j] ].push_back(gr[i - 1][j]);
                        graph[gr[i - 1][j] ].push_back(gr[i][j] );
                    }
                    
                    if(gr[i][j - 1] > 0){
                        graph[gr[i][j] ].push_back(gr[i][j - 1]);
                        graph[gr[i][j - 1] ].push_back(gr[i][j] );
                    }
                }

        memset(match, -1, sizeof(match) );

        long ans = 0;

        for(int i = 1; i < cont; i++){
            memset(visited, 0, sizeof(visited) );
            ans += augmenting(i);
        }

        cout << ans << endl;

        for(int i = 1; i < cont; i++) graph[i].clear();
    }
}