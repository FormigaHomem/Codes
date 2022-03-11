#include <bits/stdc++.h>
 
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e3 + 10
 
using namespace std;
 
long N, M, visited[MAXN][MAXN], rooms, l[] = {1, -1, 0, 0}, c[] = {0, 0, 1, -1};
char mapa[MAXN][MAXN];
 
void dfs_in_grid(int x, int y){
    visited[x][y] = 1;
 
    for(int i = 0; i < 4; i++){
        int a = x + l[i], b = y + c[i];
 
        if(a >= 1 and a <= N and b >= 1 and b <= M and !visited[a][b] and mapa[a][b] == '.') dfs_in_grid(a, b);
    }
}
 
int main(){_
 
    cin >> N >> M;
 
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++) cin >> mapa[i][j];
 
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            if(mapa[i][j] == '.' and !visited[i][j]){
                rooms++;
                dfs_in_grid(i, j);
            }
    cout << rooms << endl;
}
