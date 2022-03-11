#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 1010
#define INF 0x3f3f3f3f
#define LOG 20
#define f first
#define s second
#define lsb(x) x & (-x)
#define endl "\n"

using namespace std;

long N, M, ft[MAXN][MAXN], tab[MAXN][MAXN];

void update(int x, int _y){
    for(;x <= N; x += lsb(x) )
        for(int y = _y; y <= N; y += lsb(y) ) ft[x][y]++;
}

long query(int x, int _y){
    long ret = 0;
    for(; x > 0; x -= lsb(x) )
        for(int y = _y; y > 0; y -= lsb(y) ) ret += ft[x][y];
    return ret;
}

long query(int x1, int y1, int x2, int y2){
    return query(x2, y2) - query(x1, y2) - query(x2, y1) + query(x1, y1);
}

int main(){
    fastio

    while(cin >> N >> M){

        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++){
                cin >> tab[i][j];
                if(tab[i][j]) update(i, j);
            }

        for(int i = 1; i <= M; i++){
            int x, x1, x2, y, y1, y2;
            cin >> x >> y;
            update(x, y);
            cin >> x1 >> y1 >> x2 >> y2;
            cout << query(x1 - 1, y1 - 1, x2, y2) << endl;
        }

        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++) ft[i][j] = tab[i][j] = 0;
    }
}