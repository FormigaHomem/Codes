#include <iostream>
#include <algorithm>
#include <cstring>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 2e3
#define INF 0x3f3f3f3f

using namespace std;

long int N, M, dist[MAXN][MAXN], U, V, W, menor = MAXN * MAXN;

int main(){
    cin >> N >> M;

    memset(dist, INF, sizeof(dist) );

    for(int j = 1; j <= M; j++){
        cin >> U >> V >> W;
        dist[U][V] = W;
        dist[V][U] = W;
    }

    for(int i = 1; i <= N; i++) dist[i][i] = 0;

    for(int k = 1; k <= N; k++)
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    for(int i = 1; i <= N; i++) menor = min(menor, *max_element(dist[i] + 1, dist[i] + N + 1) );

    cout << menor << endl;
}
