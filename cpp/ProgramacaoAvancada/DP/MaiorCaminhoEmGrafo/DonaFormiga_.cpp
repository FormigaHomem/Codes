#include <bits/stdc++.h>

#define MAXN (int) 2e2 + 10
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

long S, T, P, h[MAXN], dp[MAXN];
vector<int> tunel[MAXN];

long ans(int v){
    if(dp[v] != -1) return dp[v];
    
    long resp = 0;
    for(int u : tunel[v])
        resp = max(resp, 1 + ans(u) );
    
    return dp[v] = resp;
}

int main(){_
    memset(dp, -1, sizeof(dp) );

    cin >> S >> T >> P;

    for(int i = 1; i <= S; i++) cin >> h[i];

    for(int i = 1; i <= T; i++){
        int u, v;
        cin >> u >> v;

        if(h[u] > h[v]) tunel[u].push_back(v);
        else if(h[v] > h[u]) tunel[v].push_back(u);
    }


    cout << ans(P) << endl;
}