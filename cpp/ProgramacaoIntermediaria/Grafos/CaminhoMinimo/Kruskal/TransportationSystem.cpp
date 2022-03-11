#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e3 + 10
#define f first
#define s second

using namespace std;

typedef pair<int, int> pii;
typedef pair<double, pii> pdii;

int T, N, r, pai[MAXN], peso[MAXN], states, c = 1;
pii coord[MAXN];
double roads, railroads;

int Find(int x){
    if(pai[x] == x) return x;
    return pai[x] = Find(pai[x] );
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

    cin >> T;

    while(T--){
        states = 1;

        vector<pdii> aresta = {};

        cin >> N >> r;

        for(int i = 1; i <= N; i++){
            int u, v, w;
            pai[i] = i, peso[i] = 0;

            cin >> u >> v;
            coord[i] = {u, v};
        }

        for(int i = 1; i < N; i++)
            for(int j = i + 1; j <= N; j++){
                double dist = hypot(coord[j].f - coord[i].f, coord[j].s - coord[i].s);
                aresta.push_back( {dist, {i, j} } );
            }

        sort(aresta.begin(), aresta.end() );

        for(pdii i : aresta){
            double dist = i.f;
            int u = i.s.f, v = i.s.s;

            if(Find(u) != Find(v) ){
                join(u, v);

                if(dist > r){
                    railroads += dist;
                    states++;
                }

                else roads += dist;
            }
        }

        cout << "Case " << "#" << c++ << ": " << states << " " << (roads - (int) roads < (int) roads + 1 - roads? (int) roads : (int) roads + 1) << " " << (railroads - (int) railroads < (int) railroads + 1 - railroads? (int) railroads : (int) railroads + 1) << endl;

        roads = railroads = 0;
    }

}