#include <iostream>

#define MAXN (int) 1e3 + 10

using namespace std;

int N, M, toca[MAXN][MAXN], l[] = {1, -1, 0, 0}, c[] = {0, 0, 1, -1}, mark[MAXN][MAXN];

void grid(int x, int y, int cont){

    if(toca[x][y] == 3){
        cout << cont << endl;
        return;
    }
    

    mark[x][y] = 1;

    for(int i = 0; i < 4; i++){
        int a = x + l[i], b = y + c[i];

        if(a < 1 or a > N or b < 1 or b > M or mark[a][b] or !toca[a][b]) continue;

        grid(a, b, cont + 1);
    }
    return;
}

int main(){

    cin >> N >> M;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++) cin >> toca[i][j];

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            if(toca[i][j] == 2)  grid(i, j, 1);
}