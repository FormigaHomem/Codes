#include <bits/stdc++.h>

#define MAXN (int) 1e5 + 10
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD (long) 1e9 + 7

using namespace std;

int N, M, dp[MAXN];
vector<int> teleport[MAXN];

long ans(int id){
    if(id > N) return 0;
    if(id == N) return 1;

    if(dp[id] != -1) return dp[id];

    long resp = 0;

    for(int u : teleport[id]) resp += ans(u); resp %= MOD;
    
    return dp[id] = resp %= MOD;
}

int main(){
    memset(dp, -1, sizeof(dp) );

    cin >> N >> M;

    for(int i = 1; i <= M; i++){
        int u, v;
        cin >> u >> v;
        teleport[u].push_back(v);
    }

    cout << ans(1) << endl;
}