#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (long) 2e5 + 10

using namespace std;

typedef long long ll;

ll T, N, Q, segt[4 * MAXN], lazy[4 * MAXN];

// push: O(1)
void push(int idx, int l, int r){
    if(lazy[idx] != 0){
        segt[idx] += (r - l + 1) * lazy[idx];

        if(l != r){
            int next = 2 * idx;
            lazy[next] = lazy[idx];
            lazy[next + 1] = lazy[idx]; 
        }
        lazy[idx] = 0;
    }
}

// update: O(logN)
void update(int idx, int l, int r, int x, int y, ll k){
    push(idx, l, r);

    if(l > y or r < x) return;
    if(l >= x and r <= y){
        lazy[idx] = k;
        push(idx, l, r);
        return;
    }

    int mid = (l + r) / 2, next = 2 * idx;

    update(next, l, mid, x, y, k);
    update(next + 1, mid + 1, r, x, y, k);

    segt[idx] = segt[next] + segt[next + 1];
}

// query: O(logN)
ll query(int idx, int l, int r, int x, int y){
    push(idx, l, r);

    if(l > y or r < x) return 0;
    if(l >= x and r <= y) return segt[idx];

    int mid = (l + r) / 2, next = 2 * idx;

    return query(next, l, mid, x, y) + query(next + 1, mid + 1, r, x, y);
}

int main(){_

    cin >> T;

    while(T--){
        cin >> N >> Q;

        while(Q--){
            ll task, p, q, v;

            cin >> task >> p >> q;

            --p, --q;
            if(task) cout << query(1, 0, N - 1, p, q) << endl;
            else{
                cin >> v;
                update(1, 0, N - 1, p, q, v);
            }
        }

        memset(segt, 0, sizeof(segt) );
        memset(lazy, 0, sizeof(lazy) );
    }
}