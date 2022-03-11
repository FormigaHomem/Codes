#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e3 + 10
#define MAXV (int) 1e5 + 10

using namespace std;

long V, M, coin[MAXN], dp[MAXV][MAXN];

int ans(long x, int id){
    if(!x) return 1;
    if(x < 0 or id > M) return 0;

    if(dp[x][id] != -1) return dp[x][id];

    int ret = 0;

    for(int i = id; i <= M; i++){
        ret |= ans(x - coin[i], i + 1);
        if(ret) return dp[x][id] = ret;
    }
    
    return dp[x][id] = ret;
}

int main(){_
    memset(dp, -1, sizeof(dp) );

    cin >> V >> M;

    for(int i = 1; i <= M; i++) cin >> coin[i];

    cout << (ans(V, 1)? 'S' : 'N');
}