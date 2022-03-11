#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e3
#define f first
#define s second

using namespace std;

typedef pair<int, int> pii;

int N, M, C, K, toll_fee[MAXN], U, V, P;
bool visited[MAXN];
vector<pii> neighbors[MAXN];

long int Dijkstra(){
    for(int i = 0; i < N; i++) toll_fee[i] = MAXN * MAXN;
    toll_fee[K] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > fila;
    fila.push({0, K});

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

        if(davez < C){
            for(pii i : neighbors[davez]){
                if(i.s == davez + 1){
                    int p = i.f, atual = i.s;

                    if(toll_fee[atual] >= toll_fee[davez] + p){
                        toll_fee[atual] = toll_fee[davez] + p;
                        fila.push( {toll_fee[atual], atual} );
                    }
                }
            }
            continue;
        }

        visited[davez] = true;

        for(pii i : neighbors[davez]){
            int p = i.f, atual = i.s;

            if(toll_fee[atual] > toll_fee[davez] + p){
                toll_fee[atual] = toll_fee[davez] + p;
                fila.push( {toll_fee[atual], atual} );
            }
        }
    }

    return toll_fee[C - 1];
}

int main(){

    while(cin >> N >> M >> C >> K, K){

        for(int j = 1; j <= M; j++){
            cin >> U >> V >> P;

            neighbors[U].push_back( {P, V} );
            neighbors[V].push_back( {P, U} );
        }

        cout << Dijkstra() << endl;

        memset(visited, 0, sizeof(visited) );
        memset(neighbors, 0, sizeof(neighbors) );
    }
}
