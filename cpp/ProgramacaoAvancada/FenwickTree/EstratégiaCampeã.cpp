#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e3 + 10
#define lsb(x) x & (-x)

using namespace std;

long N, M, Q, ft[MAXN][MAXN], has_player;

// update: O(logNlogN)
void update(int x1, int y1, int value){
    for(int x = x1; x <= N; x += lsb(x) )
        for(int y = y1; y <= M; y += lsb(y) ) ft[x][y] += value;
}

// query: O(logNlogN)
int query(int X, int Y){
    int ans = 0;
    for(int x = X; x > 0; x -= lsb(x) )
        for(int y = Y; y > 0; y -= lsb(y) ) ans += ft[x][y];

    return ans;
}

// query: O(logNlogN)
int query(int x1, int y1, int x2, int y2){
    return query(x2, y2) - (x1 == y1 and y1 == 1? 0 : query(x2, y1 - 1) + query(x1 - 1, y2) ) + query(x1 - 1, y1 - 1);
}

int main(){_

    while(cin >> N >> M){

        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= M; j++){
                cin >> has_player;
                if(has_player) update(i, j, 1);
            }

        cin >> Q;

        while(Q--){
            int type, x1, y1, x2, y2;

            cin >> type >> x1 >> y1 >> x2 >> y2;

            if(!type){
                update(x1, y1, -1);
                update(x2, y2, 1);
            }
            else cout << query(x1, y1, x2, y2) << endl;
        }

        memset(ft, 0, sizeof(ft) );
    }
}