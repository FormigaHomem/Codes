#include <iostream>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int l[] = {1, -1, 0, 0}, c[] = {0, 0, 1, -1}, moves;
char tabuleiro[10][10];
bool visited[10][10];

void dfs_in_grid(int x, int y){
    visited[x][y] = true;

    for(int i = 0; i < 4; i++){
        int a = x + l[i], b = y + c[i];


        if(a < 1 or a > 7 or b < 1 or b > 7 or visited[a + l[i] ][b + c[i] ] or visited[a][b] or tabuleiro[a + l[i] ][b + c[i] ] != 'o' or tabuleiro[a][b] != 'o') continue;
        moves++;
    }
    return;
}

int main(){_

    for(int i = 1; i <= 7; i++)
        for(int j = 1; j <= 7; j++) cin >> tabuleiro[i][j];

    for(int i = 1; i <= 7; i++)
        for(int j = 1; j <= 7; j++)
            if(tabuleiro[i][j] == '.') dfs_in_grid(i, j);

    cout << moves << endl;
}
