#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 20

using namespace std;

long Q, L, X, Y, notX, notY, startX, startY, matrix[MAXN][MAXN], visited[MAXN][MAXN], is_content[MAXN][MAXN], is_border[MAXN][MAXN], c[] = {0, 0, 1, -1}, l[] = {1, -1, 0, 0}, ans;

int border_definer(int x, int y){
    visited[x][y] = 1;

    for(int i = 0; i < 4; i++){
        int a = x + l[i], b = y + c[i];
        if(a == X and b == Y and x != notX and y != notY) return is_border[x][y] = 1;

        if(a >= 1 and a <= L and b >= 1 and b <= L and !visited[a][b]){
            if(x == X and y ==  Y) notX = a, notY = b;
            is_border[x][y] = border_definer(a, b);
            if(is_border[x][y]) ans++;
            
            return is_border[x][y];
        }
    }

    return 0;
}

void content_definer(int x, int y){
    is_content[x][y] = 1;

    for(int i = 0; i < 4; i++){
        int a = x + l[i], b = y + c[i];

        if(a >= 1 and a <= L and b >= 1 and b <= L and !is_content[a][b] and !matrix[a][b]){
            content_definer(a, b);
            ans++;
        }
    }

}

int main(){_

    cin >> Q;

    while(Q--){
        cin >> L;

        for(int i = 1; i <= L; i++)
            for(int j = 1; j <= L; j++)
                cin >> matrix[i][j];

        for(int i = 1; i <= L; i++)
            for(int j = 1; j <= L; j++)
                if(matrix[i][j] and !visited[i][j]){
                    int adj = 0; 
                    if(!startX and !startY) startX = i, startY = j;

                    for(int k = 0; k < 4; k++){
                        int a = i + l[k], b = j + c[k];

                        if(a >= 1 and a <= L and b >= 1 and b <= L and matrix[a][b]){
                            adj++;
                            if(startX == i or startY == j) startX += l[k], startY += c[k];
                        }
                    }

                    cout << adj << endl;

                    if(adj < 2) continue;

                    X = i, Y = j;
                    border_definer(i, j);

                    if(!is_border[i][j] and !startX and !startY) startX = startY = 0;
                }

        content_definer(startX, startY);

        cout << "\n\n";

        for(int i = 1; i <= L; i++){
            for(int j = 1; j <= L; j++) cout << is_border[i][j] << " ";
            cout << endl;
        }

        cout << endl;

        for(int i = 1; i <= L; i++){
            for(int j = 1; j <= L; j++) cout << is_content[i][j] << " ";
            cout << endl;
        }

        cout.precision(2);
        cout << "\n" << fixed << ans/2 << endl;
    }

}