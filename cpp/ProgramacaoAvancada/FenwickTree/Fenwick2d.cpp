#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (long) 1e4 + 10
#define lsb(x) x & (-x)

using namespace std;

long N, M, Q, ft[MAXN][MAXN], v[MAXN][MAXN];

// update: logNlogN
void update(int x, int y, long value){
    while(x <= N){
        while(y <= M){
            ft[x][y] += value;
            y += lsb(y);
        }
        x += lsb(x);
    }
}

// build: NlogNlogN
void build(long N, long M){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            update(i, j, v[i][j]);
        }
    }
}

// query: logNlogN
long long query(int x, int y){
    long long sum = 0;

    while(x > 0){
        while(y > 0){
            sum += ft[x][y];
            y -= lsb(y);
        }
        x -= lsb(x);
    }

    return sum;
}

// query: logNlogN
long long query(int x1, int y1, int x2, int y2){
    return query(x2, y2) - (x2 == y2 and y2 == 1? 0 : query(x2, y1 - 1) + query(x1 - 1, y2) ) + query(x1 - 1, y1 - 1);
}

int main(){

    cin >> N >> M >> Q;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> v[i][j];
        }
    }

    build(N, M);

    while(Q--){
        long x1, y1, x2, y2, newValue;
        string task;

        cin >> task >> x1 >> y1;

        if(task == "update"){
            cin >> newValue;
            update(x1, y1, newValue - v[x1][y1]);
            v[x1][y1] = newValue;
        }

        else{
            cin >> x2 >> y2;
            cout << query(x1, y1, x2, y2) << endl;
        }
    }

}