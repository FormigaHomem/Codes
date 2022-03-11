#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define f first
#define s second
#define lsb(x) x & (-x)
#define INF 0x3f3f3f3f
#define LOG 20
#define MAXN 110

using namespace std;

long N, M, P, Sx, Sy, Nx, Ny, visited[MAXN][MAXN], grid[MAXN][MAXN], c[] = {1, -1, 0, 0}, l[] = {0, 0, 1, -1};

bool ans(int x, int y){
    visited[x][y] = 1;
    if(x == Nx and y == Ny) return 1;

    bool ret = 0;

    for(int i = 0; i < 4; i++)
        for(int j = 1; j <= 3; j++){
            int a = x + j * c[i], b = y + j * l[i];

            if(a < 1 or a > N or b < 1 or b > M or visited[a][b] or !grid[a][b]) continue;
            ret |= ans(a, b);
            if(ret) return ret;
        }

    return ret;
}

int main(){_

    cin >> N >> M >> P;

    for(int i = 1; i <= P; i++){
        int x, y;
        cin >> x >> y;
        grid[x][y] = 1;
    }

    cin >> Sx >> Sy >> Nx >> Ny;

    cout << (ans(Sx, Sy)? "S\n" : "N\n");

}