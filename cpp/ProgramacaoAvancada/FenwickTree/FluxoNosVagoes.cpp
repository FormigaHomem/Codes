#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 101010
#define INF 0x3f3f3f3f
#define LOG 20
#define f first
#define s second
#define lsb(x) x & (-x)
#define endl "\n"

using namespace std;

long N, M;
long long ft[MAXN];

void update(int x, int k){
    while(x <= N){
        ft[x] += k;
        x += lsb(x);
    }
}

long long query(int x){
    long ret = 0;
    while(x > 0){
        ret += ft[x];
        x -= lsb(x);
    }

    return ret;
}

long long query(int x1, int x2, int y1, int y2, int arrangement){
    if(arrangement == 1) return query(x2) - query(x1 - 1) + query(y2) - query(y1 - 1);
    else return query(max(x2, y2) ) - query(min(x1, y1) - 1);
}

int main(){
    fastio

    cin >> N >> M;

    while(M--){
        int task;
        cin >> task;

        if(task == 1){
            int x, y;
            cin >> x >> y;
            
            update(x, y);
        }

        else{
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            if(a > b) swap(a, b);
            if(c > d) swap(c, d);

            if(b < c or d < a) cout << query(a, b, c, d, 1) << endl;
            else cout << query(a, b, c, d, 2) << endl;
        }
    }
}