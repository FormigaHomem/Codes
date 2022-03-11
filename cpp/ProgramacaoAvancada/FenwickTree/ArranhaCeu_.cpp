#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e5 + 10
#define lsb(x) (x & -x)

using namespace std;

long N, Q, A[MAXN], fwt[MAXN], op, K, P;

void update(int x, int v){

    while(x <= N){
        fwt[x] += v;
        x += lsb(x);
    }
}

long soma(int x){

    long s = 0;

    while(x > 0){
        s += fwt[x];
        x -= lsb(x);
    }

    return s;
}

int main(){_

    cin >> N >> Q;

    for(int i = 1; i <= N; i++){
        cin >> A[i];
        update(i, A[i]);
    }

    while(Q--){
        cin >> op >> K;

        if(!op){
            cin >> P;
            update(K, P - A[K]);
            A[K] = P;
        }

        else cout << soma(K) << endl;
    }
}