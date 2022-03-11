#include <bits/stdc++.h>
 
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 6e2
#define INF 9e9
#define f first
#define s second
 
using namespace std;
 
typedef pair<int, int> pii;
typedef long long ll;
 
ll N, M, S, D, U, V, P, dist[MAXN];
vector<pii> rua[MAXN];
vector<int> shortest_path[MAXN];
bool removed[MAXN][MAXN];
 
void dfs(int v){
    
    if(v != S)
        for(int i : shortest_path[v]){
            removed[v][i] = true;
            dfs(i);
        }
}
 
ll Dijkstra(){ // Caminho minimo.
    for (int i = 0; i < N; i++) dist[i] = INF; // Seto as distancias como sendo infinitas.
        
    dist[S] = 0; // A distancia de S até S é 0. 
    priority_queue<pii, vector<pii>, greater<pii> > fila; // Uma fila de prioridade que vai ordenar decrescentemente as distâncias.
    fila.push( {0, S} ); // E inicio a fila com o vértice de partida. 
 
    while(!fila.empty() ){ // Enquanto a fila nn estiver vazia.
        int X = fila.top().s, Dist = fila.top().f; // X recebe o vértice atual e D recebe a menor distancia possivel de S até X;
        fila.pop(); // Tiro esse vértice da fila.
        
        if(Dist > dist[X]) continue;
 
       for (pii i : rua[X]){ // Itero os vértice de X.
            int d = i.f + Dist, atual = i.s; // d recebe a distância de X a atual e atual recebe o vértice de X atual.
            
            if(dist[atual] > d and !removed[atual][X]){ // Se a distância de S até atual for maior doq a distância de S até X mais a distância de X até atual 
                dist[atual] = d; // Então atualizo a distância ate atual.
                shortest_path[atual].clear(); // Apago o antigo menor caminho até esse vértice. 
                shortest_path[atual].push_back(X); // E adiciono na lista de menores caminhos até X o vértice atual.
                
                fila.push( {dist[atual], atual} ); // E coloco na fila a distância até atual e o vértice atual.
            }
            else if(dist[atual] == d and !removed[atual][X]) shortest_path[atual].push_back(X); // Tds os caminhos mínimos devem ser excluídos.
        }
        
    }
    
    return (dist[D] == INF? -1 : dist[D]); // E agora será retornada a distancia de S até D, caso exista um quase caminho minimo, senão, retornará -1.  
}
 
int main(){_
 
    while(cin >> N >> M, M){ // Recebo N e M, a quantidade de vértices e de arestas, respectivamente, enquanto M != 0.
        cin >> S >> D; // Recebo S e D, a origem e o destino.
 
        for(int i = 1; i <= M; i++){ // Um loop q vai rodar a quantidade de arestas, q vai ser justamente para receber todas as arestas.
            cin >> U >> V >> P; // Recebo essa aresta.
            rua[U].push_back( {P, V} ); // E digo que há um caminho de U para V com distancia P.
        }
 
        Dijkstra();
        dfs(D);
       
        cout << Dijkstra() << endl; // Digo qual é o quase menor caminho, que caso não exista retornará -1.
        memset(removed, false, sizeof(removed) );
        
        for (int i = 0; i < N; i++) rua[i].clear(); // E reseto rua.
    }
}