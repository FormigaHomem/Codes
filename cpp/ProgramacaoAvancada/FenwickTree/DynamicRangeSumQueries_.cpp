#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (long) 2e5
#define lsb(x) x & (-x)

using namespace std;

typedef long long ll;

ll N, Q;
vector<ll> ft, v;

// update: O(logN)
void update(int x, ll delta){
    for(int i = x; i <= N; i += lsb(i) )
        ft[i] += delta;
}

// build: O(NlogN)
void build(){
    ft.assign(N + 1, 0);

    for(int i = 1; i <= N; i++)
        update(i, v[i]);
}

// query: O(logN)
ll query(int x){
    ll sum = 0;
    for(int i = x; i > 0; i -= lsb(i) )
        sum += ft[i];
    return sum; 
}

// query: O(logN)
ll query(int l, int r){
    return query(r) - (l == 1? 0 : query(l - 1) );
}

int main(){_

    cin >> N >> Q;

    v.resize(N + 1);

    for(int i = 1; i <= N; i++) cin >> v[i];

    build();

    while(Q--){
        ll T, a, b;
        cin >> T >> a >> b;

        if(T == 1){
            update(a, b - v[a] );
            v[a] = b;
        }

        else cout << query(a, b) << "\n";
    }
}