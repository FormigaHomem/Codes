#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 20

using namespace std;

long L, Q, X, Y, perimeter = 1, grid[MAXN][MAXN], visited[MAXN][MAXN], c[8] = {0, 0, 1, -1, 1, 1, -1, -1}, l[8] = {1, 1, 0, 0, 1, -1, -1, 1};

void Perimeter(int x, int y){
    visited[x][y] = 1;

    for(int i = 0; i < 8; i++){
        int a = x + c[i], b = y + l[i];

        if(a < 1 or a > L or b < 1 or b > L or visited[a][b] or !grid[a][b]) continue;
        perimeter++;
        Perimeter(a, b);
    }
}

int main(){_

    cin >> Q;

    while(Q--){

        cin >> L;

        for(int i = 1; i <= L; i++)
            for(int j = 1; j <= L; j++) cin >> grid[i][j];
    
        int ok = 0;
        for(int i = 1; i <= L; i++){
            for(int j = 1; j <= L; j++)
                if(!visited[grid[i][j] ]){
                    Perimeter(i, j);
                    ok = 1;
                    X = i; Y = j;
                    break;
                }
            if(ok) break;
        }

        

    }
}