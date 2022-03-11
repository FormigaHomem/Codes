#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (long) 2e5 + 10

using namespace std;

typedef long long ll;

ll N, Q, v[MAXN], blocks[MAXN], root;

// build: O(N)
void build(int N){
    root = sqrt(N) + 1;

    for(int i = 0; i < N; i++){
        blocks[i/root] += v[i]; 
    }
}

// query: O(srqt(N) )
ll query(int l, int r){
    ll ans = 0;

    for(int i = l; i <= r;){
        if(i % root == 0 and i + root - 1 <= r){
            ans += blocks[i/root];
            i += root;
        }

        else ans += v[i++];
    }

    return ans;
}

// update: O(1)
void update(int id, ll k){
    blocks[id/root] += k - v[id];
    v[id] = k;
}

int main(){_

    cin >> N >> Q;

    for(int i = 0; i < N; i++) cin >> v[i];

    build(N);

    while(Q--){
        int task, a, b;

        cin >> task >> a >> b;

        if(task == 1){
            update(a - 1, b);
        }

        else{
            cout << query(a - 1, b - 1) << endl;
        }
    }

}