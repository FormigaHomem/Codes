#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int)5e2 + 10
#define f first
#define s second
#define INF (long) 1e9 + 10

using namespace std;

typedef pair<long, long> pii;

long long L, C, tabuleiro[MAXN][MAXN], dist[MAXN][MAXN];
bool visited[MAXN][MAXN];

long long bfs_in_grid(){
    dist[1][1] = 0;
    queue<pii> fila;
    fila.push( {1, 1} );

    while(!fila.empty() ){
        int x = fila.front().f, y = fila.front().s, d = dist[x][y];
        fila.pop();
        //cout << endl << x << " " << y << " " << tabuleiro[x][y] << " " << d << endl;
        visited[x][y] = true;

        for(int a = x - 2; a <= x + 2; a++){
            if(a < 1 or a > L) continue;
            for(int b = y - 2; b <= y + 2; b++){
                if(b < 1 or b > C or !tabuleiro[a][b] or visited[a][b]) continue;
                //cout << a << " " << b << " " << matrix[a][b] << " " << dist[a][b] << endl;
                dist[a][b] = min(dist[a][b], (long long)d + 1);
                fila.push( {a, b} );
                visited[a][b] = true;
            }
        }
    }

    if(dist[L][C] == INF) return -1;
    else return dist[L][C];
}

int main(){_

    cin >> L >> C;

    for(int i = 1; i <= L; i++)
        for(int j = 1; j <= C; j++){
            cin >> tabuleiro[i][j];
            dist[i][j] = INF;
        }

    cout << bfs_in_grid() << endl;
}