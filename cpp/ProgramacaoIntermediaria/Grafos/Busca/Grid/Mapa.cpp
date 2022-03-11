#include <bits/stdc++.h>

using namespace std;

#define MAXN  110

int N, M, K, destroyed = 0, z = 0, pieces = 0;
pair<int, int> pos;
vector<pair<int, int> > navy[MAXN * MAXN];
char mapa[MAXN][MAXN];
bool discovered[MAXN * MAXN][MAXN * MAXN];

int l[] = {1, -1, 0, 0};
//{1, 0}, {-1, 0}, {0, 1}, {0, -1}
int c[] = {0, 0, 1, -1};

void grid_way(int x, int y){
    discovered[x][y] = true;
    pos = make_pair(x, y);

    for(int i = 0; i < 4; i++){
        int a = x + l[i];
        int b = y + c[i];
        if(a < 0 or a >= N or b < 0 or b >= M or discovered[a][b] or mapa[a][b] == '.') continue;
        grid_way(a, b);
    }
}

int main(){

    cin >> N >> M;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++) cin >>  mapa[i][j];

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(mapa[i][j] == 'o' and !discovered[i][j]){
                grid_way(i, j);
            }

    cout << pos.first + 1 << " " << pos.second + 1;
}
