#include <iostream>
#include <vector>
#include <queue>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 2e3
#define f first
#define s second

using namespace std;

typedef pair<int, int> pii;

int N, M, holes[MAXN], S, T, B;
bool visited[MAXN];
vector<pii> neighbors[MAXN];

long int Dijkstra(){
    for(int i = 1; i <= N + 1; i++) holes[i] = MAXN * MAXN;
    holes[0] = 0;
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

            if(holes[atual] >= holes[davez] + b){
                holes[atual] = holes[davez] + b;
                fila.push( {holes[atual], atual} );
            }
        }
    }

    return holes[N + 1];
}

int main(){
    cin >> N >> M;

    for(int j = 1; j <= M; j++){
        cin >> S >> T >> B;
        neighbors[S].push_back( {B, T} );
        neighbors[T].push_back( {B, S} );
    }

    cout << Dijkstra() << endl;
}
