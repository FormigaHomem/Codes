#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e5 + 10

using namespace std;

vector<int> in_love[MAXN];
long visited[MAXN], ans;

int dfs(int v, int color){
    visited[v] = color;

    for(int u : in_love[v]){
        if(visited[u] == visited[v]) return 1;
        else if(!visited[u] and dfs(u, color) ) return 1;
    }

    return 0;
}

int main(){

    string u, v;
    long N = 1;
    map<string, int> mp;

    while(cin >> u >> v){
        if(mp.find(u) == mp.end() )
            mp[u] = N++;
        if(mp.find(v) == mp.end() )
            mp[v] = N++;
        in_love[mp[u] ].push_back(mp[v]);
    }
    
    long color = 0;
    for(int i = 1; i < N; i++)
        if(!visited[i]) ans += dfs(i, ++color);

    cout << ans << endl;
}