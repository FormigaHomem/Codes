#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL);
#define MAXN 101010
#define f first
#define s second

using namespace std;

typedef pair<int, int> pii;

long N, S, K, F, Q, resp[MAXN][25];
vector<long> graph[MAXN];
queue<pii> fila;

int main(){_

    cin >> N >> S;

    for(int i = 1; i <= N; i++){
        cin >> K; 
        for(int j = 1; j <= K; j++){
            cin >> F;
            resp[i][F] = 1;
        }
    }

    for(int i = 1; i < N; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    fila.emplace(S, 0);

    while(!fila.empty() ){
        auto p = fila.front();
        fila.pop();

        for(auto v : graph[p.f]){
            if(v == p.s) continue;
            for(int i = 1; i <= 25; i++)
                resp[v][i] = (resp[v][i] == 1 or resp[p.f][i] == 1? 1 : 0);
            fila.push(pii(v, p.f) );
        }
    }

    cin >> Q;

    while(Q--){
        int d;
        cin >> d;
        cout << count(resp[d], resp[d] + 25, 1) << endl;
    }

}