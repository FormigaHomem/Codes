#include <iostream>
#include <vector>
#include <queue>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 2e3
#define f first
#define s second

using namespace std;

typedef pair<int, int> pii;

long int N, M, cost[MAXN], U, V, W;
bool visited[MAXN];
vector<pii> neighbors[MAXN];

long int Prim(){
    for(int i = 0; i < N; i++) cost[i] = MAXN * MAXN;
    cost[0] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > fila;
    fila.push({0, 0});

    while(true){
        int davez = -1;

        while(!fila.empty() ){
            int atual = fila.top().s;
            fila.pop();

            if(!visited[atual]){
                davez = atual;
                break;
            }
        }

        if(davez == -1) break;

        visited[davez] = true;

        for(pii i : neighbors[davez]){
            int b = i.f, atual = i.s;

            if(cost[atual] > b and !visited[atual]){
                cost[atual] = b;
                fila.push( {cost[atual], atual} );
            }
        }
    }

    int ret = 0;
    for(int i = 0; i < N; i++) ret += cost[i];

    return ret;
}

int main(){
    cin >> N >> M;

    for(int j = 1; j <= M; j++){
        cin >> U >> V >> W;
        neighbors[U].push_back( {W, V} );
        neighbors[V].push_back( {W, U} );
    }

    cout << Prim() << endl;
}
