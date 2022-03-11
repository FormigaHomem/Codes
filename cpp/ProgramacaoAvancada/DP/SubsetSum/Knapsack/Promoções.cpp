#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 1010

using namespace std;

long N, M, dp[MAXN][2 * MAXN], weight[MAXN], value[MAXN];

long solve(int id, long w){
    if(!id) return w? -(0x3f3f3f3f) : 0;

    if(dp[id][w] != -1) return dp[id][w];

    long &ans = dp[id][w];
    ans = solve(id - 1, w);

    if(weight[id] <= w) ans = max( {ans, value[id] + solve(id - 1, w - weight[id]), value[id] + solve(id, w - weight[id]) } );
    return ans;
}

int main(){

    while(cin >> N >> M){
        

        memset(dp, -1, sizeof(dp) );

        for(int i = 1; i <= N; i++)
            cin >> weight[i] >> value[i];

        cout << solve(N, M) << endl;
    }