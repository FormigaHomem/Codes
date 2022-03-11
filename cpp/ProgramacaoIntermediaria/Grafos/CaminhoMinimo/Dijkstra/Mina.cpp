#include <iostream>
#include <vector>
#include <queue>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 2e2
#define f first
#define s second
#define t top()

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int N, mina[MAXN][MAXN], fails[MAXN][MAXN], c[] = {1, -1, 0, 0}, l[] = {0, 0, 1, -1};
bool processado[MAXN][MAXN];

void Dijkstra(){
    fails[1][1] = 0;
    priority_queue<piii, vector<piii>, greater<piii> > fila;
    fila.push({0, {1, 1} });

    while(true){
        pii davez = {-1, -1};

        while(!fila.empty() ){
            pii atual = fila.top().s;
            fila.pop();

            if(!processado[atual.f][atual.s]){
                davez = atual;
                break;
            }
        }

        if(davez.f == -1) break;

        processado[davez.f][davez.s] = true;

        if(mina[davez.f][davez.s]) ++fails[davez.f][davez.s];

        for(int i = 0; i < 4; i++){
            int a = davez.f + c[i], b = davez.s + l[i];

            if(a < 1 or a > N or b < 1 or b > N or fails[a][b] <= fails[davez.f][davez.s]) continue;
            fails[a][b] = fails[davez.f][davez.s];
            fila.push( {fails[a][b], {a, b} } );
        }
    }

}

int main(){
    cin >> N;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++){
            cin >> mina[i][j];
            fails[i][j] = MAXN;
        }

    Dijkstra();

    cout << fails[N][N];
}
