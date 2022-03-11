#include<bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 20101
#define grey 1
#define white 0
#define INF  0x3f3f3f3f

using namespace std;

long N, M, center, radial, grau[MAXN], dist[MAXN], visited[MAXN], dp[MAXN];
vector<int> graph[MAXN];

long ans(int v, int last){

    if(grau[v] == 1 or v == center) return -INF;
    if(dp[v] != -1) return dp[v];

    long ret = 0;
    for(auto u : graph[v]){
        if(u == last) continue;

        ret = max(0L, 1 + ans(u, v) );
        dp[v] = max(dp[v], ret);

        cout << v << " " << u << " " << dp[v] << endl;
    }

    return dp[v];
}

int main(){

    memset(dp, -1, sizeof(dp) );

    cin >> N >> M;

    for(int i = 1; i <= M; i++){
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
        grau[u]++; grau[v]++;
        if(grau[u] == 5) center = u;
        else if(grau[v] == 5) center = v;
    }
    
    for(int i = 1; i <= N; i++) 
        if(i != center and grau[i] > 2){
            radial = i;
            break;
        }

    cout << ans(radial, 0) << endl;
}   