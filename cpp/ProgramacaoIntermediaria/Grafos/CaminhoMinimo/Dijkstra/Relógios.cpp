#include <iostream>
#include <vector>
#include <queue>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 2e2
#define f first
#define s second
#define t top()

using namespace std;

typedef long long ll;
typedef pair<ll, pair<int, int> > piii;

ll L, C, K, mapa[MAXN][MAXN], tempo[MAXN][MAXN], c[] = {1, -1, 0, 0}, l[] = {0, 0, 1, -1};
bool processado[MAXN][MAXN];

long long int Dijkstra(){
    tempo[1][1] = 0;
    priority_queue<piii, vector<piii>, greater<piii> > fila;
    fila.push( {0, {1, 1} } );

    while(true){
        pair<int, int> davez = {-1, -1};

        while(!fila.empty() ){
            pair<int, int> atual = fila.top().s;
            fila.pop();

            if(!processado[atual.f][atual.s]){
                davez = atual;
                break;
            }
        }

        if(davez.f == -1) break;

        processado[davez.f][davez.s] = true;

        for(int i = 0; i < 4; i++){
            int a = davez.f + c[i], b = davez.s + l[i];

            if(a < 1 or a > L or b < 1 or b > C or tempo[a][b] <= tempo[davez.f][davez.s]) continue;

            int espera, hora = (tempo[davez.f][davez.s] + K) % K, time = tempo[davez.f][davez.s];

            if(mapa[a][b] == -1 or (hora + 1 == mapa[a][b] or hora == K - 1 and mapa[a][b] == 0) ) tempo[a][b] = time + 1;

            else{

                if(mapa[davez.f][davez.s] != -1) continue;

                if(mapa[a][b] <= hora) espera = K + mapa[a][b] - hora;
                else espera = mapa[a][b] - hora;

                tempo[a][b] = time + espera;
            }

            fila.push( {tempo[a][b], {a, b} } );
        }
    }
    if(tempo[L][C] != (ll) 1e8) return tempo[L][C];
    return -1;

}

int main(){
    cin >> L >> C >> K;

    for(int i = 1; i <= L; i++)
        for(int j = 1; j <= C; j++){
            cin >> mapa[i][j];
            tempo[i][j] = (ll) 1e8;
        }

    cout << Dijkstra() << endl;
}
