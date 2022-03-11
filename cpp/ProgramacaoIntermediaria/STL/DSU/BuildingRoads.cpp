#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e5 + 10
#define f first
#define s second

using namespace std;

typedef pair<int, int> pii;

long N, M, pai[MAXN], peso[MAXN], node0;
vector<pii> roadsToBeBuilt;

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

    cin >> N >> M;

    for(int i = 1; i <= N; i++) pai[i] = i;

    for(int i = 1; i <= M; i++){
        int u, v;
        cin >> u >> v;

        join(u, v);
    }

    node0 = 1;
    for(int i = 1; i <= N; i++)
        if(Find(i) != Find(node0) ){
            join(i, node0);
            roadsToBeBuilt.push_back( {i, node0} );
            node0 = Find(node0);
        }
    cout << roadsToBeBuilt.size() << endl;
    for(auto u : roadsToBeBuilt) cout << u.f << " " << u.s << endl;

}