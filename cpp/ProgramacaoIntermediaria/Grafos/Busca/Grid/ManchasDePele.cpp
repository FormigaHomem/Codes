#include <iostream>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 2e3

using namespace std;

int N, M, mancha[MAXN][MAXN], manchas, c[] = {1, -1, 0, 0}, l[] = {0, 0, 1, -1};
bool visited[MAXN][MAXN];

void dfs_in_grid(int x, int y){
    visited[x][y] = true;

    for(int i = 0; i < 4; i++){
        int a = x + c[i], b = y + l[i];

        if(mancha[a][b] and !visited[a][b]) dfs_in_grid(a, b);
    }
}

int main(){

    cin >> N >> M;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++) cin >> mancha[i][j];

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            if(!visited[i][j] and mancha[i][j]) {
                dfs_in_grid(i, j);
                manchas++;
            }

    cout << manchas;
}
