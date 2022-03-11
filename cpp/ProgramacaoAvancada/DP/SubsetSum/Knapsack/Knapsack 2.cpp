#include <iostream>
#include <cstring>
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);
#define f first
#define s second

using namespace std;

typedef pair<int, pair<int, int> > p;

long int N, M;
bool marked[110][60];
pair<int, int> toy[110];
p dp[110][60];

p best_choose(p a, p b){
    if(a.f != b.f){
        return (a > b? a : b);
    }
    return (a <= b? a : b);
}

p solve(int id, long int weight){
    if(id == M or weight >= 50) return {0, {0, 0} };

    if(marked[id][weight]) return dp[id][weight];

    marked[id][weight] = true;

    p nao_coloca = solve(id + 1, weight);

    if(toy[id].s + weight <= 50){
        p aux = solve(id + 1, weight + toy[id].s);
        p coloca = {toy[id].f + aux.f, {toy[id].s + aux.s.f,  ++aux.s.s} };

        return dp[id][weight] = best_choose(coloca, nao_coloca);
    }
    return dp[id][weight] = nao_coloca;

}

int main(){
    boost;

    cin >> N;

    while(N--){

        cin >> M;
        for(int i = 0; i < M; i++) cin >> toy[i].f >> toy[i].s;

        p a = solve(0, 0);
        cout << a.f << " brinquedos\nPeso: " << a.s.f << " kg\nsobra(m) " << M - a.s.s << " pacote(s)\n\n";

        memset(dp, 0, sizeof(dp) );
        memset(marked, false, sizeof(marked) );
        memset(toy, 0, sizeof(toy) );
    }

}
