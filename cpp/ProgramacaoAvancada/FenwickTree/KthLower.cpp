#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 101010

using namespace std;

typedef long long ll;

long N, Q, segt[4 * MAXN];

void update(int idx, int l, int r, int x){
    if(l == r){
        segt[idx]++;
        return;
    }

    int mid = (l + r) / 2, next = 2 * idx;
    if(x <= mid) update(next, l, mid, x);
    else update(next + 1, mid + 1, r, x);

    segt[idx] = segt[next] + segt[next + 1];
}

ll query(int idx, int l, int r, int kth){
    if(l == r) return segt[l];

    int mid = (l + r) / 2, next = 2 * idx;

    if(segt[next] >= kth) return query(idx, l, mid + 1, kth);
    else return query(idx + 1, mid + 1, r, kth - segt[next]);
}

int main(){

    cin >> N >> Q;

    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        update(1, 0, MAXN - 1, x);
    }

    while(Q--){
        int k;
        cin >> k;

        cout << query(1, 0, MAXN - 1, k) << endl;
    }
}