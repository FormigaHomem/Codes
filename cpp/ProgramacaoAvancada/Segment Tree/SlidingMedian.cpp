#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (long) 2e5 + 10

using namespace std;

typedef long long ll;

long N, k, segt[4 * MAXN], lazy[4 * MAXN], v[MAXN];
vector<ll> ans;

void build(int idx, int l, int r, int x){
    if(l == r){
        segt[idx]++;
        return;
    }

    int mid = (l + r) / 2, next = 2 * idx;

    if(x <= mid) build(next, l, mid, x);
    else build(next + 1, mid + 1, r, x);

    segt[idx] = segt[next] + segt[next + 1]; 
}

void update(int idx, int l, int r, int x, int k){
    if(l == r){
        segt[idx] = k;
        return;
    }

    int mid = (l + r) / 2, next = 2 * idx;
    if(x <= mid) update(next, l, mid, x, k);
    else update(next + 1, mid + 1, r, x, k);

    segt[idx] = segt[next] + segt[next + 1];
}

ll query(int idx, int l, int r, int kth){
    if(l == r) return l;

    int mid = (l + r) / 2, next = 2 * idx;

    if(segt[next] >= kth) return query(next, l, mid + 1, kth);
    else return query(next + 1, mid + 1, r, kth - segt[next]);
}

int main(){

    cin >> N >> k;

    for(int i = 0; i < N; i++){
        cin >> v[i];
        
        if(i >= k){
            ans.push_back(query(1, 0, MAXN - 1, (i + i - k - 1) / 2) );
            update(1, 0, MAXN - 1, v[i - k], v[i - k] - 1);
            update(1, 0, MAXN - 1, v[i], v[i]);
        }
        
        else build(1, 0, MAXN - 1, v[i]);
    }

    ans.push_back(query(1, 0, MAXN - 1, (N + N - k - 1) / 2) );

    for(auto i : ans) cout << i << " ";
}