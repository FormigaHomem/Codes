#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 2 * ( (long) 1e4 + 10)
#define INF 0x3f3f3f3f
#define f first
#define s second

using namespace std;

typedef pair<long, int> pli;

long N, M, dist[MAXN], ans;
vector<pli> road[MAXN];

long Dijkstra(){
    dist[1] = 0;
    priority_queue<pli, vector<pli>, greater<pli> > pq;
    pq.push( {0, 1} );

    while(!pq.empty() ){
        long v = pq.top().s, D = pq.top().f;
        pq.pop();

        if(D > dist[v]) continue;

        for(auto i : road[v]){
            long u = i.s, w = i.f;

            if(dist[u] > D + w){
                dist[u] = D + w;
                pq.push( {dist[u], u} );
            }
        }
    }

    return dist[N];
}

int main(){_

    cin >> N >> M;

    for(int i = 1; i <= M; i++){
        long u, v, w;
        cin >> u >> v >> w;
        road[u].push_back( {w, v + N} );
        road[v].push_back( {w, u + N} );
        road[u + N].push_back( {w, v} );
        road[v + N].push_back( {w, u} );
    }

    memset(dist, INF, sizeof(dist) );
    ans = Dijkstra();
    ans = (ans >= INF? -1 : ans);
    cout << ans << endl;
}