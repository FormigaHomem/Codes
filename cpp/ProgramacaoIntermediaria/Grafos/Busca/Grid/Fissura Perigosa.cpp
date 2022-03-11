// Grid! IMPORTANTE!
#include <iostream>

using namespace std;

#define MAXN  510

int N, M;
char mapa[MAXN][MAXN];
bool mark[MAXN][MAXN];

int l[] = {1, -1, 0, 0};
//{1, 0}, {-1, 0}, {0, 1}, {0, -1}
int c[] = {0, 0, 1, -1};

void grid(int x, int y){

    int integer = 0;
    for(int i = 0; i < 4; i++){
        int a, b;
        a = x + l[i];
        b = y + c[i];

        if(mapa[a][b] != '*') integer = mapa[a][b] - '0';
        if( (a == 0 and b == 0 and integer <= M) or (a >= 0 and a < N and b >= 0 and b < N and !mark[a][b] and mapa[a][b] != '*' and ( (mapa[a - 1][b] == '*'  or mapa[a + 1][b] == '*' or mapa[a][b - 1] == '*' or mapa[a][b + 1] == '*') and integer <= M) ) ){
            mapa[a][b] = '*';
            mark[a][b] = true;
            grid(a, b);
        }
    }
    mark[x][y] = true;
    return;
}

int main(){

    cin >> N >> M;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) cin >>  mapa[i][j];

    grid(0, 0);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cout << mapa[i][j];
        cout << endl;
    }
}
