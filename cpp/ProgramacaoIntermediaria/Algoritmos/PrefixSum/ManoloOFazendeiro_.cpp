#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (long) 1e2

using namespace std;

long long N, Q, cenouras[MAXN][MAXN], total, l1, c1, l2, c2;

int main(){_

    cin >> N;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++) cin >> cenouras[i][j];

    cin >> Q;

    for(int k = 1; k <= Q; k++){
        cin >> l1 >> c1 >> l2 >> c2;

        for(int i = l1; i <= l2; i++)
            for(int j = c1; j <= c2; j++){
                total += cenouras[i][j];
                cenouras[i][j] = 0;
            }
    }

    cout << total;
}