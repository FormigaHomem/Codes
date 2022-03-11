#include <bits/stdc++.h>

using namespace std;

#define MAXN  110

int N, M, K, destroyed = 0, z = 0, pieces = 0;
pair<int, int> shots[MAXN * MAXN];
vector<pair<int, int> > navy[MAXN * MAXN];
char mapa[MAXN][MAXN];
bool all_navies[MAXN * MAXN][MAXN * MAXN];

int l[] = {1, -1, 0, 0};
//{1, 0}, {-1, 0}, {0, 1}, {0, -1}
int c[] = {0, 0, 1, -1};

void grid_all_navies(int x, int y){
    all_navies[x][y] = true;
    navy[z].push_back(make_pair(x, y) );

    for(int i = 0; i < 4; i++){
        int a = x + l[i];
        int b = y + c[i];
        if(a < 0 or a >= N or b < 0 or b >= M or all_navies[a][b] or mapa[a][b] == '.') continue;
        grid_all_navies(a, b);
    }
}

int main(){

    cin >> N >> M;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++) cin >>  mapa[i][j];

    cin >> K;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(mapa[i][j] == '#' and !all_navies[i][j]){
                z++;
                grid_all_navies(i, j);
            }
    for(int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        shots[i] = make_pair(a - 1, b - 1);
    }

    for(int i = 1; i <= z; i++){
        for(pair<int, int> j : navy[i])
            for(int k = 0; k < K; k++)
                if(shots[k] == j) {
                    pieces++;
                    break;
                }

        if(pieces == navy[i].size()) destroyed++;
        pieces = 0;
    }

    cout << destroyed;
}
