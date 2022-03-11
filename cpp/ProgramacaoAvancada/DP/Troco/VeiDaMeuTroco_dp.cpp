#include <bits/stdc++.h>

#define MAXN (int) 1e3 + 10
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N, M, dp[MAXN], valor[MAXN];

int ans(int x){
    if(!x) return 1;
    if(x < 0) return 0;

    if(dp[x] != -1) return dp[x];

    for(int i = 1; i <= N; i++)
        if(ans(x - valor[i] ) ) return dp[x - valor[i] ] = 1;

    return dp[x] = 0;
}

int main(){_
    memset(dp, -1, sizeof(dp) );

    cin >> N >> M;

    for(int i = 1; i <= N; i++) cin >> valor[i];

    cout << (ans(M)? 'S' : 'N');
}