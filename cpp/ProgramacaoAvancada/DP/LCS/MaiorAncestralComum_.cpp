#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (long) 1e3 + 10

using namespace std;

long N, M, s1[MAXN], s2[MAXN], dp[MAXN][MAXN], ans;

long lcs(int a, int b){
    if(dp[a][b] >= 0) return dp[a][b];
    
    if(a <= 0 or b <= 0) return dp[a][b] = 0;

    if(s1[a] == s2[b]) return 1 + lcs(a - 1, b - 1);
    return dp[a][b] = max(lcs(a - 1, b), lcs(a, b - 1) );
}

int main(){_
    memset(dp, -1, sizeof(dp) );

    cin >> N >> M;

    for(int i = 1; i <= N; i++) cin >> s1[i];
    for(int i = 1; i <= M; i++) cin >> s2[i];

    ans = lcs(N, M);

    cout << N - ans << " " << M - ans << endl;
}
