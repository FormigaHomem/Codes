#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (long)2e5 + 10

using namespace std;

long long N, q, num, psa[MAXN], l, r;

int main(){_

    cin >> N >> q;

    for(int i = 1; i <= N; i++){
        cin >> num;
        psa[i] = psa[i - 1] + num;
    }

    while(q--){
        cin >> l >> r;
        
        if(l == 1) cout << psa[r] << endl;
        else cout << psa[r] - psa[l - 1] << endl;
    }
}