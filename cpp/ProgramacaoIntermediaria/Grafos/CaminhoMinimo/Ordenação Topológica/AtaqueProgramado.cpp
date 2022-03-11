#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e4 + 10
#define f first
#define s second

using namespace std;

typedef pair<int, pair<int, int> > piii;

int N, M, S;

bool ord(piii a, piii b){
    if(a.f != b.f) return a.f > b.f;
    return a.s.f < b.s.f;
}

int main(){_

    while(cin >> N >> M >> S, N){

        int grau[MAXN] = {}, inimigos[MAXN], refens[MAXN], allies = S;
        vector<int> vigia[MAXN] = {};
        priority_queue<piii, vector<piii>, function<bool(piii, piii) > > lista(ord);

        for(int i = 1; i <= N; i++) cin >> inimigos[i];
        for(int i = 1; i <= N; i++) cin >> refens[i];

        for(int i = 1; i <= M; i++){
            int u, v;
            cin >> u >> v;
            vigia[u].push_back(v);
            grau[v]++;
        }

        for(int i = 1; i <= N; i++)
            if(!grau[i]) lista.push( {inimigos[i], {refens[i], i} } );

        int ini = 0;
        while(ini < lista.size() ){
            piii temp = lista.top(); ini++;
            int v = temp.s.s;

            if(temp.f >= allies) continue;
            allies += temp.s.f;
            
            lista.pop(); lista.push( { (long) 1e9, {temp.s.f, temp.s.s} } );

            for(int u : vigia[v]){
                grau[u]--;
                if(!grau[u]) lista.push( {inimigos[u], {refens[u], u} } );
            }
        }

        if(lista.size() < N or lista.top().f != (long) 1e9) cout << "impossivel\n";
        else cout << "possivel\n";
    }

}