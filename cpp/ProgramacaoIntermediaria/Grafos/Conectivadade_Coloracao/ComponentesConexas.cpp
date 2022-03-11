#include<bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1000

using namespace std;

long T, t, N, M, visited[MAXN], component;
vector<int> edges[MAXN];
map<int, set<int> > components;

void dfs(int v){
    visited[v] = 1;
    components[component].insert(v + 96);

    for(auto u : edges[v])
        if(!visited[u]) dfs(u);
}

int main(){

    cin >> T;

    while(T--){

        cin >> N >> M;
        for(int i = 1; i <= M; i++){
            char u, v;
            cin >> u >> v;

            int a = u - 96, b = v - 96;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }

        for(int i = 1; i <= N; i++)
            if(!visited[i]){
                ++component;
                dfs(i);
            }

        cout << "Case #" << ++t << ":\n";
        for(auto it1 = components.begin(); it1 != components.end(); it1++){
            for(auto it2 = it1->second.begin(); it2 != it1->second.end(); it2++) cout << (char) *it2 << ",";
            cout << endl;
        }

        cout << component << " connected components\n\n";

        for(int i = 1; i <= N; i++){
            visited[i] = 0;
            edges[i].clear();
            
        }
        
        components.clear();
        component = 0;
    }
}