#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e5 + 10
#define INF (long long) 1e10
#define f first
#define s second

using namespace std;

typedef pair<long, long> pii;
typedef pair<long, pii> piii;

long long N, C, A, B, dist[MAXN], lower_way[MAXN];
vector<pii> way[MAXN];

long long Dijkstra(){
    priority_queue<piii, vector<piii>, greater<piii> > fila;
    if(A > B) fila.push( {0, {A, -1} } );
    else fila.push( {0, {A, A + 1} } );
    dist[A] = 0;

    while(!fila.empty() ){
        long X = fila.top().s.f, D = fila.top().f, Search = fila.top().s.s;
        fila.pop();

        for(pii i : way[X]){
            long atual = i.s, d = i.f;

            if(dist[atual] > D + d and atual >= B and Search == -1){
                dist[atual] = D + d;
                fila.push( {dist[atual], {atual, -1} } );
                lower_way[atual] = X;
            }

            else if(dist[atual] > D + d and (atual < B or atual == Search) ){
                dist[atual] = D + d;
                fila.push( {dist[atual], {atual, atual + 1} } );
                lower_way[atual] = X;
            }
        }
    }

    return dist[B];
}

void backtracking(int v){

    if(v != A) backtracking(lower_way[v]);
    cout << v << " ";
}

int main(){_

    cin >> N >> C >> A >> B;

    for(int i = 1; i <= C; i++){
        long a, b, d;
        cin >> a >> b >> d;
        way[a].push_back( {d, b} );
        way[b].push_back( {d, a} );
        dist[a] = dist[b] = INF;
    }

    cout << Dijkstra() << endl;
    backtracking(B);
}