#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 2e5 + 10
#define INF (int) 1e10

using namespace std;

typedef long long ll;

int N, Q, v[MAXN], root;
map<int, int> blocks[500];

// build: O(N)
void build(int N){
    root = sqrt(N) + 1;

    for(int i = 0; i < N; i++){
        blocks[i/root][v[i] ]++; 
    }
}

// query: O(srqt(N) )
int query(int l, int r){
    int ans = INF;

    for(int i = l; i <= r;){
        if(i % root == 0 and i + root - 1 <= r){
            ans = min(ans, blocks[i/root].begin()->first);
            i += root;
        }

        else ans = min(ans, v[i++]);
    }

    return ans;
}

// update: O(1)
void update(int id, int k){
    if(--blocks[id/root][v[id] ] == 0) blocks[id/root].erase(v[id]);
    v[id] = k;
    blocks[id/root][v[id] ]++;
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