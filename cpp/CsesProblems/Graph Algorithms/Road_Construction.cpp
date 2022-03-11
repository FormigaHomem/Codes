#include <bits/stdc++.h>
 
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e5 + 10
 
using namespace std;
 
long N, M, peso[MAXN], pai[MAXN], maior, comp;
 
int Find(int x){
    if(pai[x] == x) return x;
    return pai[x] = Find(pai[x] );
}
 
void join(int a, int b){
    a = Find(a); b = Find(b);
 
    if(peso[a] > peso[b]){
        pai[b] = a;
        peso[a] += peso[b];
        maior = max(maior, peso[a]); comp--;
    }
 
    else if(peso[b] > peso[a]){
        pai[a] = b;
        peso[b] += peso[a];
        maior = max(maior, peso[b]); comp--;
    }
    
    else{
        pai[b] = a;
        peso[a] += peso[b];
        comp--; maior = max(maior, peso[a]);
    } 
}
 
int main(){
 
    cin >> N >> M;
    comp = N, maior = 1;
    for(int i = 1; i <= N; i++){
        pai[i] = i;
        peso[i] = 1;
    }
 
    for(int i = 1; i <= M; i++){
        int u, v;
        cin >> u >> v;
        if(Find(u) != Find(v) ) join(u, v);
        cout << comp << " " << maior << endl;
    }
}
