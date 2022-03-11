#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 3e2

using namespace std;

long N, M, x, y, z, entrosamento[MAXN][MAXN], sum = -1, resp[5];

int main(){_

    cin >> N >> M;

    for(int i = 1; i <= M; i++){
        cin >> x >> y >> z;
        entrosamento[x][y] = z;
        entrosamento[y][x] = z;
    }

    for(int i = 1; i <= N; i++)
        for(int j = i + 1; j <= N; j++)
            for(int k = j + 1; k <= N; k++)
                if(entrosamento[i][j] + entrosamento[j][k] + entrosamento[i][k] > sum){
                    sum = entrosamento[i][j] + entrosamento[j][k] + entrosamento[i][k];
                    resp[1] = i; resp[2] = j; resp[3] = k;
                }

    for(int i = 1; i <= 3; i++) cout << resp[i] << " ";
}