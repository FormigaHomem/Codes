#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e3 + 10
#define f first
#define s second
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, pll> pdll;

ll T, N, M, pai[MAXN], peso[MAXN], x, y;

ll Find(ll x){
    if(pai[x] == x) return x;
    return pai[x] = Find(pai[x]);
}

void join(ll a, ll b){

    a = Find(a);
    b = Find(b);

    if(peso[a] > peso[b]) pai[b] = a;
    else if(peso[b] > peso[a]) pai[a] = b;
    else{
        pai[b] = a;
        peso[a]++;
    }
}

int main(){

    cin >> T;

    while(T--){

        cin >> N;

        pll vertice[N + 10];
        pdll aresta[N * N + 10];
        vector<pll> mst;

        for(int i = 1; i <= N; i++){
            cin >> x >> y;
            vertice[i] = {x, y};
            pai[i] = i;
            peso[i] = 0;
        }

        cin >> M;

        for(int i = 1; i <= M; i++){
            cin >> x >> y;
            join(x, y);
        }

        int index = 1;
        for(int i = 1; i < N; i++)
            for(int j = i + 1; j <= N; j++)
                aresta[index++] = {hypot(vertice[i].f - vertice[j].f, vertice[i].s - vertice[j].s), {i, j} };

        sort(aresta + 1, aresta + index);
        
        bool used = false;
        for(int i = 1; i < index; i++){
            ll a = aresta[i].s.f, b = aresta[i].s.s;
            if(Find(a) != Find(b) ){
                used = true;
                join(a, b);
                mst.push_back( {a, b} );
            }
        }

        if(used)
            for(int i = 0; i < mst.size(); i++) cout << mst[i].f << " " << mst[i].s << endl;
        else cout << "No new highways need\n";

        if(T) cout << endl;
    }
}