#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e4 + 10
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, pair<ll, ll> > plll;

ll t, c = 1, N, M, A, pai[MAXN], peso[MAXN];

int Find(int x){
    if(pai[x] == x) return x;
    return pai[x] = Find(pai[x]);
}

void join(int a, int b){

    a = Find(a), b = Find(b);

    if(peso[a] > peso[b]) pai[b] = a;
    else if(peso[b] > peso[a]) pai[a] = b;
    else{
        pai[b] = a;
        peso[a]++;
    }
}

int main(){_

    cin >> t;

    while(t--){

        vector<plll> aresta;

        cin >> N >> M >> A;
        int airports = N;

        for(int i = 1; i <= N; i++){
            pai[i] = i;
            peso[i] = 0;
        }

        for(int i = 1; i <= M; i++){
            int u, v, w;
            cin >> u >> v >> w;
            aresta.push_back( {w, {u, v} } );
            aresta.push_back( {w, {v, u} } );
        }

        sort(aresta.begin(), aresta.end() );

        ll cost = 0;
        for(int i = 1; i < aresta.size(); i++){
            ll d = aresta[i - 1].f, u = aresta[i - 1].s.f, v = aresta[i - 1].s.s;

            if(Find(u) != Find(v) and cost + (airports * A) > cost + d + ( (airports - 1) * A) ){
                airports--;
                join(u, v);
                cost += d;
            }
        }


        cout << "Case #" << c++ << ": " << cost + (airports * A) << " " << airports << endl;
    }
}