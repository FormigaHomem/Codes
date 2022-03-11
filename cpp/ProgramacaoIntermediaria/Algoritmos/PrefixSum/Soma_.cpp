#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (long) 5e5 + 10

using namespace std;

long long N, K, num, psa[MAXN], possibilities;

int main(){_

    cin >> N >> K;

    for(int i = 1; i <= N; i++){
        cin >> num;
        psa[i] = psa[i - 1] + num;
    }

    for(int i = 1; i <= N; i++) possibilities += (upper_bound(psa + i, psa + N + 1, K + psa[i - 1]) - psa) - (lower_bound(psa + i, psa + N + 1, K + psa[i - 1]) - psa);

    cout << possibilities << endl;
}