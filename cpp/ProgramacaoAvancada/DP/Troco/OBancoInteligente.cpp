#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 5e3 + 10

using namespace std;

long long S, valor[] = {0, 2, 5, 10, 20, 50, 100}, qntd[10], dp[MAXN][10];

long long ans(long long x, int id){
    if(!x) return 1;
    if(x < 0 or id > 6) return 0;

    if(dp[x][id] != -1) return dp[x][id];

    long long ret = 0;
    for(int i = 0; i <= qntd[id]; i++){

        if(valor[id] * i > x) break;

        ret += ans(x - valor[id] * i, id + 1);
    }

    return dp[x][id] = ret;
}

int main(){_
    memset(dp, -1, sizeof(dp) );

    cin >> S;

    for(int i = 1; i <= 6; i++) cin >> qntd[i];

    cout << ans(S, 1) << endl;
}
