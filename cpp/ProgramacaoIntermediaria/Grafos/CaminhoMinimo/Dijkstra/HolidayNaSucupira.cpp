#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (ll) 1e4 + 10
#define INF (ll) 1e12
#define f first
#define s second
#define ll long long
#define pii pair<ll, ll>

using namespace std;

ll N, M, U, V, P, dist[MAXN];
vector<pii> interesting_point[MAXN];
vector<int> shortest_path[MAXN];
bool removed[MAXN][MAXN];

void dfs(int v){

    if(v != 1)
        for(int i = 0; i < shortest_path[v].size(); i++){
            int atual = shortest_path[v][i];
            removed[atual][v] = removed[v][atual] = true; 
            dfs(atual);
        }
}

ll Dijkstra(){
    for(int i = 1; i <= N; i++) dist[i] = INF;
    dist[1] = 0;

    priority_queue<pii, vector<pii>, greater<pii> > fila;
    fila.push( {0, 1} );

    while(!fila.empty() ){
        ll D = fila.top().f, X = fila.top().s;
        fila.pop();

        if(D > dist[X]) continue;

        for(int i = 0; i < interesting_point[X].size(); i++){
            ll atual = interesting_point[X][i].s, d = interesting_point[X][i].f;
            
            if(dist[atual] > d + D and !removed[X][atual]){
                dist[atual] = d + D;
                shortest_path[atual].clear();
                shortest_path[atual].push_back(X);
                fila.push( {dist[atual], atual} );
            }
            else if(dist[atual] == d + D and !removed[X][atual]) shortest_path[atual].push_back(X);
        }
    }

    return (dist[N] == INF? -1 : dist[N]);
}

int main(){_

    cin >> N >> M;

    for(int i = 1; i <= M; i++){
        cin >> U >> V >> P;
        interesting_point[U].push_back( {P, V} );
        interesting_point[V].push_back( {P, U} );
    }

    Dijkstra();
    dfs(N);
    cout << Dijkstra() << endl;
}