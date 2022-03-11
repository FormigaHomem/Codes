#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e4 + 10
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll T, N, visited[MAXN];


int main(){_

    cin >> T;

    while(T--){
        cin >> N;
        
        vector<pll> road[MAXN] = {};

        for(int i = 1; i < N; i++){
            visited[1] = visited[i + 1] = 0;
            int u, v, w;
            cin >> u >> v >> w;
            road[u].push_back( {w, v} );
            road[v].push_back( {w, u} );
        }

        ll ans = 0, elements = 1;
        queue<int> q;
        q.push(1);

        while(q.size() ){
            int v = q.front();
            q.pop();
            visited[v] = 1;

            for(pll u : road[v])
                if(!visited[u.s]){
                    q.push(u.s); elements++;
                    ans += elements * u.f;
                } 
        }

        cout << ans << endl;
    }
    
}