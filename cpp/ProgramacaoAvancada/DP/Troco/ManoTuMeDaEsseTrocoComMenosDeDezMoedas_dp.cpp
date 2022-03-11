#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e3 + 10

using namespace std;

int N, M, dp[MAXN], valor[MAXN];

int ans(int x, int moedas){
    if(!x) return moedas;
    if(x < 0) return 0;

    if(dp[x] != -1) return dp[x];

    int ret = MAXN;
    for(int i = 1; i <= N; i++)
        if(ans(x - valor[i], moedas + 1) ) ret = min(ans(x - valor[i], moedas + 1), ret);
    
    return dp[x] = (ret == MAXN? 0 : ret);
}

int main(){_
    memset(dp, -1, sizeof(dp) );

    cin >> N >> M;

    for(int i = 1; i <= N; i++) cin >> valor[i];

    int Ans = ans(M, 0);
    cout << (Ans < 10 and Ans? 'S' : 'N');
}