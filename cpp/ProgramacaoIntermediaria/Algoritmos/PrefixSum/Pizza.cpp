#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e5 + 10

using namespace std;

typedef long long ll;

ll N, K, psa[MAXN], psa_inv[MAXN], ans;

int main(){_

    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> K;
        psa[i] = max(psa[i - 1] + K, 0LL);
        ans = max(ans, psa[i]);
    }

    for(int i = 1; i <= N; i++) psa_inv[N - i + 1] = max(psa[N] - psa[i - 1], 0LL);

    for(int i = 1; i <= N - 2; i++) {
        auto it = lower_bound(psa_inv + 1, psa_inv + (N - i + 2) , 0, [] (int comp, int search) {return comp > search;} );
        ans = max(ans, psa[i] + *(--it) );
    }

    cout << ans << endl;
}