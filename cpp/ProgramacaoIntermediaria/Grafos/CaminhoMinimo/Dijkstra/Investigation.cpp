#include <bits/stdc++.h>

#define MAXN (ll) 1e5 + 10
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair< ll, ll > pll;

const ll MOD = 1e9 + 7;
ll N, M, a, b, c, dist[MAXN], caminhos[MAXN], mais_arestas, menos_arestas;
vector<pll> flight[MAXN];
vector<ll> arestas[MAXN];

ll Dijkstra(){
    dist[1] = 0;
    priority_queue<pll, vector<pll>, greater<pll> > fila;
    fila.push( {0, 1} );
    caminhos[1] = 1; arestas[1].push_back(0);

    while(!fila.empty() ){

        ll X = fila.top().s, D = fila.top().f;
        fila.pop();

        if(dist[X] > D) continue;

        for(pll i : flight[X]) {
            ll atual = i.s, d = i.f;
            if(dist[atual] > D + d){
                dist[atual] = D + d;

                if(arestas[atual].size() ) arestas[atual].clear();
                if(atual == N){ 
                    mais_arestas = 0; 
                    menos_arestas = (ll) 1e16; 
                }
                for(ll A : arestas[X]){
                   if(atual == N){
                        mais_arestas = max(mais_arestas, A + 1);
                        menos_arestas = min(menos_arestas, A + 1);
                    }
                    else arestas[atual].push_back(A + 1);
                }

                fila.push( {dist[atual], atual} );
                caminhos[atual] = caminhos[X] % MOD;
            }
            else if(dist[atual] == D + d){
                if(atual == N) caminhos[atual] =  (caminhos[atual] + caminhos[X]) % MOD;
                
                else caminhos[atual]++;
                
                for(ll A : arestas[X]){
                    if(atual == N){
                        mais_arestas = max(mais_arestas, A + 1);
                        menos_arestas = min(menos_arestas, A + 1);
                    }
                    else arestas[atual].push_back(A + 1);
                }
            }
        }
    }

    return dist[N];
}

int main(){_

    cin >> N >> M;

    for(int i = 1; i <= M; i++){
        cin >> a >> b >> c;
        flight[a].push_back( {c, b} );
        dist[a] = dist[b] = (ll) 1e16;
    }

    cout << Dijkstra() << " " << caminhos[N] % MOD << " " << menos_arestas << " " << mais_arestas << endl;
}