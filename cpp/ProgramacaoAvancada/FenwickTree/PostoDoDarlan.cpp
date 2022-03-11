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

long N, M, L, ft[MAXN][MAXN], Cars[MAXN][MAXN], Motocycles[MAXN][MAXN], ans, ret, cars, motocycles;

void update(int x, int _y, int k){
    for(;x <= N; x += lsb(x) )
        for(int y = _y; y <= M; y += lsb(y) ) ft[x][y] += k;
}

void updateCars(int x, int _y){
    for(;x <= N; x += lsb(x) )
        for(int y = _y; y <= M; y += lsb(y) ) Cars[x][y]++;
}

void updateMotocycles(int x, int _y){
    for(;x <= N; x += lsb(x) )
        for(int y = _y; y <= M; y += lsb(y) ) Motocycles[x][y]++;
}

void query(int x, int _y, int m){
    for(;x > 0; x -= lsb(x) )
        for(int y = _y; y > 0; y -= lsb(y) ){
            ret += ft[x][y] * m;
            cars += Cars[x][y] * m;
            motocycles += Motocycles[x][y] * m;
        }
}   

void query(int x1, int y1, int x2, int y2){
    ret = cars = motocycles = 0;
    query(x2, y2, 1), query(x1, y2, -1), query(x2, y1, -1), query(x1, y1, 1);
}

int main(){
    fastio

    cin >> N >> M;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++){
            char vehicle;
            cin >> vehicle;

            int k = (vehicle == 'C'? 25 : 12);
            update(i, j, k);
            if(vehicle == 'C') updateCars(i, j);
            else updateMotocycles(i, j);
        }

    cin >> L;

    for(int i = N; i >= L; i--)
        for(int j = M; j >= L; j--){
            query(i, j, i - L, j - L);
            if(cars and motocycles) ans = max(ans, ret);
        }

    cout << (ans? ans : -1) << endl;
}