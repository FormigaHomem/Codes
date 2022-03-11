#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 501
#define INF 0x3f3f3f3f
#define LOG 20
#define f first
#define s second
#define lsb(x) x & (-x)
#define endl "\n"

using namespace std;

typedef unsigned long long ull;

int N, P;
ull ft[MAXN][MAXN][2], blacks, whites;

void update(int x, int y1, int type){
    for(;x <= N; x += lsb(x) )
        for(int y = y1; y <= N; y += lsb(y) ) ft[x][y][type]++;
}

ull query(int x, int y1, int type){
    ull ret = 0;
    for(;x > 0; x -= lsb(x) )
        for(int y = y1; y > 0; y -= lsb(y) ) ret += ft[x][y][type];
    return ret;
}

ull query(int x1, int y1, int x2, int y2, int type){
    return query(x2, y2, type) - query(x1, y2, type) - query(x2, y1, type) + query(x1, y1, type);
}

int myUpperBound(int x, int y, int type){
    int right = min(x, y), left = 2;

    while(left < right){
        int mid = (left + right) / 2;

        if(!query(x - mid, y - mid, x, y, type) ) left = mid + 1;
        else right = mid;
    }

    if(!query(x - left, y - left, x, y, type) ) left++;
    return left;
}

int main(){
    fastio

    cin >> N >> P;

    for(int i = 1; i <= P; i++){
        int x, y;
        cin >> x >> y;
        update(x, y, 1);
    }

    while(P--){
        int x, y;
        cin >> x >> y;
        update(x, y, 0);
    }

    for(int x = N; x > 1; x--){
        for(int y = N; y > 1; y--){
            ull b = myUpperBound(x, y, 1), w = myUpperBound(x, y, 0);
            if(w > b) blacks += w - b;
            else if(b > w) whites += b - w;
        }
    }

    cout << blacks + query(N, N, 0, 0, 1) << " " << whites + query(N, N, 0, 0, 0) << endl;
}