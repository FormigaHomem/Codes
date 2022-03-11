#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e2
#define INF (long) 1e9
#define f first
#define s second

using namespace std;

typedef pair<int, int> pii;

long N, M, labirinth[MAXN][MAXN], dist[MAXN][MAXN], visited[MAXN][MAXN], c[] = {0, 0, 1, -1}, l[] = {1, -1, 0, 0};

long bfs_in_grid(){
    dist[1][1] = 0;
    queue<pii> fila;
    fila.push( {1, 1} );

    while(fila.size() ){
        int x = fila.front().f, y = fila.front().s;
        fila.pop();

        visited[x][y] = 1;
        for(int i = 0; i < 4; i++){
            int a = x + l[i], b = y + c[i];

            if(a < 1 or a > N or b < 1 or b > M) continue;

            if(!visited[a][b] and (labirinth[a][b] + dist[x][y]) % 10 <= (labirinth[x][y] + 1 + dist[x][y]) % 10){
                dist[a][b] = min(dist[a][b], dist[x][y] + 1);
                fila.push( {a, b} );
            }

            else if(!visited[a][b]){
                int j;
                for(j = 1; j <= 10; j++)
                    if( (labirinth[a][b] + dist[x][y] + j) % 10 <= (labirinth[x][y] + 1 + dist[x][y] + j) % 10) break;

                dist[a][b] = min(dist[a][b], dist[x][y] + 1 + j);
                fila.push( {a, b} );
            }
        }

    }

    return dist[N][M];
}

int main(){_

    cin >> N >> M;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++){
            cin >> labirinth[i][j];
            dist[i][j] = INF;
        }

    cout << bfs_in_grid();
}