#include <bits/stdc++.h>

#define _ ios::base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 101010

using namespace std;

typedef long long ll;

long N, Q, T, lazy[4 * MAXN], segt[4 * MAXN], v[MAXN];

// build: O(N)
void build(int idx, int l, int r){
    if(l == r){
        segt[idx] = v[l];
        return;
    }

    int mid = (l + r) / 2, next = 2 * idx;
    build(next, l, mid);
    build(next + 1, mid + 1, r);
}

// push: O(1)
void push(int idx, int l, int r){
    if(lazy[idx] != 0){ 
        segt[idx] = (r - l + 1) * lazy[idx];
        if(l != r){
            int next = 2 * idx;
            lazy[next] = lazy[idx];
            lazy[next + 1] = lazy[idx];
        }

        lazy[idx] = 0;
    }
}

// update: O(logN)
void update(int idx, int l, int r, int x, int y, int k){
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

int main(){

    cin >> T;

    while(T--){
        cin >> N >> Q;

        for(int i = 0; i < N; i++) cin >> v[i];

        build(1, 0, N - 1);

        while(Q--){
            int task, p, q, v;

            cin >> task >> p >> q;

            --p, --q;
            if(!task){
                cin >> v;
                update(1, 0, N - 1, p, q, v);
            }

            else cout << query(1, 0, N - 1, p, q);
        }
    }
}