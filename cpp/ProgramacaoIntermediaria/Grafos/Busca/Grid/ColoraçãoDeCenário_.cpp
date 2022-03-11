#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 2e3

using namespace std;

typedef pair<int, int> pii;

int N, M, visited[MAXN][MAXN], colors, columns[] = {1, -1, 0, 0}, rows[] = {0, 0, 1, -1};
char matrix[MAXN][MAXN];

void dfs_in_grid(int x, int y, int colors){
    visited[x][y] = 1;
    stack<pii> q;
    q.push( {x, y} );

    while(!q.empty() ){
        x = q.top().first, y = q.top().second;
        q.pop();
    
        for(int i = 0; i < 4; i++){
            int a = x + columns[i], b = y + rows[i];

            if(matrix[a][b] == '.' and !visited[a][b]){
                visited[a][b] = 1;
                q.push( {a, b} );
            }
        }
    }
}

int main(){

    cin >> N >> M;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++) cin >> matrix[i][j];

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            if(!visited[i][j] and matrix[i][j] == '.') dfs_in_grid(i, j, ++colors);

    cout <<  colors << endl;
}