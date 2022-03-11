#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e4 + 10
#define f first
#define s second

using namespace std;

typedef pair<int, int> pii;

long long N, O, D, P, Q, d, dist[MAXN];
bool visited[MAXN];
vector<pii> linha[MAXN];


long long bfs(){
    for(int i = 1; i<= N; i++) dist[i] = (long) 1e9;
    queue<int> q;
    q.push(O);
    dist[O] = 0;
    while(!q.empty() ){
        long v = q.front();
        q.pop();
        visited[v] = true;

        for(pii i : linha[v]){
            long atual = i.s, dis = i.f;
            if(!visited[atual]) {
                dist[atual] = min(dist[atual], dist[v] + dis);
                q.push(atual);
            }
        }
    }
    return dist[D];
}

int main(){_

    cin >> N >> O >> D;

    for(int i = 1; i < N; i++){
        cin >> P >> Q >> d;
        linha[P].push_back( {d, Q} );
        linha[Q].push_back( {d, P} );
    }

    cout << bfs();
}