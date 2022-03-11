#include <iostream>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int)3e2

int L, C, A, B, ladrilhos[MAXN][MAXN], X, Y, c[] = {1, -1, 0, 0}, l[] = {0, 0, 1, -1};
bool visited[MAXN][MAXN];

using namespace std;

void grid(int x, int y){
    visited[x][y] = true;

    for(int i = 0; i < 4; i++){
        int a = x + c[i], b = y + l[i];

        if(a < 1 or a > L or b < 1 or b > C or visited[a][b] or !ladrilhos[a][b]) continue;
        X = a;
        Y = b;
        grid(a, b);
    }
}

int main(){_

    cin >> L >> C >> A >> B;

    for(int i = 1; i <= L; i++)
        for(int j = 1; j <= C; j++) cin >> ladrilhos[i][j];

    for(int i = A; i <= L; i++)
        for(int j = B; j <= C; j++)
            if(!visited[i][j]) grid(i, j);

    cout << X << " " << Y << endl;
}
