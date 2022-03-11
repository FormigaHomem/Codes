#include <bits/stdc++.h>

#define MAXN (int) 1e5 + 10
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N, M, dp[MAXN], longest_way[MAXN];
vector<int> flight[MAXN];

long ans(int id){
    if(id >= N) return 0;
    if(dp[id] != -1) return dp[id];

    long resp = 0;
    
    for(int u : flight[id]){
        long ret = 1 + ans(u);
        if(resp < ret){
            resp = ret;
            longest_way[id] = u;
        }
        
    }

    if(resp == 0) return -MAXN;

    return dp[id] = resp;
}

void backtracking(int v){
    cout << v << " ";
    if(v != N) backtracking(longest_way[v]);
}

int main(){
    memset(dp, -1, sizeof(dp) );

    cin >> N >> M;

    for(int i = 1; i <= M; i++){
        int u, v;
        cin >> u >> v;
        flight[u].push_back(v);
    }

    ans(1);

    if(dp[1] > 0){
        cout << dp[1] + 1 << endl;
        backtracking(1);
    }
    else cout << "IMPOSSIBLE\n";
}