#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (long) 1e5 * 2 + 10
#define INF 0x3f3f3f3f

using namespace std;

long N, Q, segt[4 * MAXN], v[MAXN];

void update(int idx, int l, int r, int x, int k){
    if(l > x or r < x) return;
    if(l == r and r == x){
        segt[idx] = k;
        return;
    }

    int mid = (l + r) / 2, next = 2 * idx;

    update(next, l, mid, x, k);
    update(next + 1, mid + 1, r, x, k);

    segt[idx] = min(segt[next], segt[next + 1]);
}

void build(int idx, int l, int r){
    if(l == r){
        segt[idx] = v[l];
        return;
    }

    int mid = (l + r) / 2, next = 2 * idx;

    build(next, l, mid);
    build(next + 1, mid + 1, r);
    
    segt[idx] = min(segt[next], segt[next + 1]);
}

int query(int idx, int l, int r, int x, int y){
    if(l > y or r < x) return INF;
    if(l >= x and r <= y) return segt[idx];

    int mid = (l + r) / 2, next = 2 * idx;

    return min(query(next, l, mid, x, y), query(next + 1, mid + 1, r, x, y) );
}

int main(){_
    memset(segt, INF, sizeof(segt) );

    cin >> N >> Q;

    for(int i = 0; i < N; i++) cin >> v[i];

    build(1, 0, N - 1);

    while(Q--){
        int task, a, b;

        cin >> task >> a >> b;

        --a;
        if(task == 1) update(1, 0, N - 1, a, b);
        else cout << query(1, 0, N - 1, a, --b) << endl;
    }

}