#include<bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 5010
#define INF 0x3f3f3f3
#define LOG 20
#define lsb(x) x & (-x)
#define f first
#define s second

using namespace std;

long N, D, M, Q, price[MAXN], water[MAXN], dp[MAXN][MAXN];
vector<int> adj[MAXN], buyable;

bool dfs(int v, int last, int destiny, long w){
    water[v] += w;
    if(v == destiny) return 1;

    bool ret = 0;

    for(auto u : adj[v]){
        if(u != last) ret |= dfs(u, v, destiny, w);
        if(ret) return ret;
    }

    water[v] -= w;

    return 0;
}

long knapsack(int id, long money){
    if(id == buyable.size() or !money) return 0;

    if(dp[id][money] != -1) return dp[id][money];

    long dont_use = knapsack(id + 1, money);

    if(money >= price[buyable[id] ]){
        long use = water[buyable[id] ] + knapsack(id + 1, money - price[buyable[id] ]);
        return dp[id][money] = max(use, dont_use);
    }

    return dp[id][money] = dont_use;
}

int main(){_

    cin >> N >> D;

    memset(dp, -1, sizeof(dp) );

    for(int i = 1; i < N; i++){
        long u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> M;

    for(int i = 1; i <= M; i++){
        long id, cost;
        cin >> id >> cost;
        price[id] = cost;
        buyable.push_back(id);
    }

    cin >> Q;

    while(Q--){
        long u, v, w;
        cin >> u >> v >> w;
        dfs(u, u, v, w);
    }

    cout << knapsack(0, D) << endl;
}