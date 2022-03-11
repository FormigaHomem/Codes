#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e4 + 10

using namespace std;

long T, N, center[MAXN];
float vizinhanca[MAXN], ans;

int main(){_

    cin >> T >> N;

    for(int i = 1; i <= N; i++) cin >> center[i];

    sort(center + 1, center + N + 1);

    vizinhanca[1] = center[1] - 0 + (float) (center[1] + center[2]) / 2 - center[1];
    vizinhanca[N] = T - center[N] + (center[N] - (float) (center[N - 1] + center[N]) / 2);
    ans = min(vizinhanca[1], vizinhanca[N]);

    for(int i = 2; i < N; i++){
        vizinhanca[i] = center[i] - (float) (center[i] + center[i - 1]) / 2 + (float) (center[i] + center[i + 1]) / 2 - center[i];
        ans = min(ans, vizinhanca[i]);
    }

    cout.precision(2);
    cout << endl << fixed << ans << endl;
}