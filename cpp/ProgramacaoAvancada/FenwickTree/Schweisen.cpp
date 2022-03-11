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

long N, M, P, Q, ft[MAXN][MAXN];

void update(int x, int _y, int k){
    for(;x <= N; x += lsb(x) )
        for(int y = _y; y <= M; y += lsb(y) ) ft[x][y] += k;
}

long query(int x, int _y){
    long ret = 0;
    for(;x > 0; x -= lsb(x) )
        for(int y = _y; y > 0; y -= lsb(y) ) ret += ft[x][y];
    return ret;
}

long query(int x1, int y1, int x2, int y2){
    return query(x2, y2) - query(x1, y2) - query(x2, y1) + query(x1, y1);
}

int main(){
    fastio

    while(cin >> N >> M >> P, P){

        cin >> Q;

        while(Q--){
            char task;
            cin >> task;

            if(task == 'A'){
                int n, x, y;
                cin >> n >> x >> y;

                update(++x, ++y, n);
            }

            else{
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;

                cout << query(min(x1, x2), min(y1, y2), max(x1, x2) + 1, max(y1, y2) + 1) * P << endl;
            }
        }
        cout << endl;

        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= M; j++) ft[i][j] = 0;
    }
}