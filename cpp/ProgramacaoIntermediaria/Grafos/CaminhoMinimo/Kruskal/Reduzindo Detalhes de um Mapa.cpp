#include <iostream>
#include <algorithm>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 2e6
#define f first
#define s second

using namespace std;

typedef pair<int, pair<int, int> > piii;

long long int N, M, U, V, W, pai[MAXN], peso[MAXN], dist = 0;
piii aresta[MAXN], mst[MAXN];

int Find(int x){
    if(pai[x] == x) return x;
    return pai[x] = Find(pai[x]);
}

void join(int a, int b){

    a = Find(a);
    b = Find(b);

    if(peso[a] > peso[b]) pai[b] = a;
    else if(peso[b] > peso[a]) pai[a] = b;
    else{
        pai[b] = a;
        peso[a]++;
    }

}

int main(){_
    cin >> N >> M;

    for(int i = 1; i <= M; i++) cin >> aresta[i].f >> aresta[i].s.f >> aresta[i].s.s;

    for(int i = 1; i <= N; i++) pai[i] = i;

    sort(aresta + 1, aresta + M + 1, [](piii a, piii b){return (a.s.s < b.s.s);} );

    for(int i = 1; i <= M; i++)
        if(Find(aresta[i].f) != Find(aresta[i].s.f) ){
            join(aresta[i].f, aresta[i].s.f);
            dist += aresta[i].s.s;
        }

    cout << dist << endl;
}
