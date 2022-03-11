#include <iostream>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int)3e2

int H, L, mosaico[MAXN][MAXN], menor_area = MAXN * MAXN, c[] = {1, -1, 0, 0}, l[] = {0, 0, 1, -1}, area;
bool visited[MAXN][MAXN];

using namespace std;

void grid(int x, int y, int integer){
    area++;
    visited[x][y] = true;

    for(int i = 0; i < 4; i++){
        int a = x + c[i], b = y + l[i];

        if(a < 0 or a >= H or b < 0 or b >= L or visited[a][b] or mosaico[a][b] != integer) continue;
        grid(a, b, integer);
    }
}

int main(){_

    cin >> H >> L;

    for(int i = 0; i < H; i++)
        for(int j = 0; j < L; j++) cin >> mosaico[i][j];

    for(int i = 0; i < H; i++){
        for(int j = 0; j < L; j++){
            if(!visited[i][j]) {
                grid(i, j, mosaico[i][j]);
                menor_area = min(menor_area, area);
                area = 0;
            }
        }
    }

    cout << menor_area << endl;
}
