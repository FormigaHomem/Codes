#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 201010

using namespace std;

typedef long long ll;

ll N, Q, v[MAXN], segt[4 * MAXN];

// build: O(N)
void build(int idx, int l, int r){
    if(l == r){
        segt[idx] = v[l];
        return;
    }

    int mid = (l + r) / 2, next = 2 * idx;

    build(next, l, mid);
    build(next + 1, mid + 1, r);
    
    segt[idx] = segt[next] + segt[next + 1];
}

// update: O(logN)
void update(int idx, int l, int r, int x, int y, ll k){
    if(l > y or r < x) return;
    if(l >= x and r <= y){
        segt[idx] = k;
        return;
    }

    int mid = (l + r) / 2, next = 2 * idx;

    update(next, l, mid, x, y, k);
    update(next + 1, mid + 1, r, x, y, k);

    segt[idx] = segt[next] + segt[next + 1];
}

// query: O(logN)
ll query(int idx, int l, int r, int x, int y){
    if(l > y or r < x) return 0;
    if(l >= x and r <= y){
        return segt[idx];
    }

    int mid = (l + r) / 2, next = 2 * idx;

    return query(next, l, mid, x, y) + query(next + 1, mid + 1, r, x, y);
}

int main(){_

    cin >> N >> Q;

    for(int i = 0; i < N; i++) cin >> v[i];

    build(1, 0, N - 1);

    while(Q--){
        ll task, x, y;

        cin >> task >> x >> y;

        --x;
        if(task == 1) update(1, 0, N - 1, x, x, y);
        else cout << query(1, 0, N - 1, x, --y) << endl;
    }
}