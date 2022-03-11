#include <bits/stdc++.h>
 
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 2e5 + 10
#define f first
#define s second
 
using namespace std;
 
typedef pair<long, long> pll;
typedef pair<long, pll> plll;
 
long long N, M, a, b, c, pai[MAXN], peso[MAXN], dist, vertices = 1;
plll aresta[MAXN];
 
int Find(int x){
    if(pai[x] == x) return x;
    return pai[x] = Find(pai[x]);
}
 
void join(int A, int B){
 
    A = Find(A);
    B = Find(B);
 
    if(peso[A] > peso[B]) pai[B] = A;
    else if(peso[B] > peso[A]) pai[A] = B;
    else{
        pai[B] = A;
        peso[A]++;
    }
 
    return;
}
 
int main(){
 
    cin >> N >> M;
 
    for(int i = 1; i <= M; i++){
        cin >> aresta[i].f >> aresta[i].s.f >> aresta[i].s.s;
        pai[aresta[i].f] = aresta[i].f; pai[aresta[i].s.f] = aresta[i].s.f;
    }
 
    sort(aresta + 1, aresta + M + 1, [] (plll a, plll b) {return a.s.s < b.s.s;} );
 
    for(int i = 1; i <= M; i++){
 
        if(Find(aresta[i].f) != Find(aresta[i].s.f) ){
            join(aresta[i].f, aresta[i].s.f);
            dist += aresta[i].s.s;
            vertices++;
        }
    }
 
    if(vertices == N) cout << dist << endl;
    else cout << "IMPOSSIBLE\n";
}
