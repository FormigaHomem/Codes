#include <iostream>
#include <vector>
#include <queue>
#include <map>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (ull) 1e7 + 10
#define f first
#define s second

using namespace std;

typedef unsigned long long ull;
typedef pair<ull, string> pis;
typedef pair<string, ull> psi;

ull T, Y, M, X;
map<string, map<string, ull> > terminal;
map<string, ull> anticalmas, aux1, aux2;
map<string, bool> visited;
string O, D, A, B;


void Dijkstra(){
    anticalmas[O] = 0;
    priority_queue<pis, vector<pis>, greater<pis> > fila;
    fila.push( {0, O} );

    while(true){
        string davez = "$";

        while(!fila.empty() ){
            string atual = fila.top().s;
            fila.pop();

            if(!visited[atual]){
                davez = atual;
                break;
            }
        }

        if(davez == "$") break;

        visited[davez] = true;

        for(psi i : terminal[davez]){
            int b = i.s, bonus = (anticalmas[davez] % b == 0 or davez == O? anticalmas[davez] : b * ( (anticalmas[davez] / b) + 1) ) - anticalmas[davez];
            string atual = i.f;

            if(anticalmas[atual] >= anticalmas[davez] + Y + bonus){
                anticalmas[atual] = anticalmas[davez] + Y + bonus;
                fila.push( {anticalmas[atual], atual} );
            }
        }
    }
}

int main(){_
    cin >> T;
    for(int t = 1; t <= T; t++){
        cin >> O >> D >> Y >> M;

        for(int j = 1; j <= M; j++){
            cin >> A >> B >> X;
            terminal[A][B] = X;

            anticalmas[A] = MAXN * MAXN;
            anticalmas[B] = MAXN * MAXN;
        }

        Dijkstra();
        if(anticalmas[D] != MAXN * MAXN and anticalmas[O] != MAXN * MAXN) cout << "Caso #" << t << ": " << anticalmas[D] << " anticalmas" << endl;
        else cout << "Caso #" << t << ": Destino inalcancavel" << endl;
        terminal.clear();
        anticalmas.clear();
        visited.clear();
    }
}
