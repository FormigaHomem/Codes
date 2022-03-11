#include <iostream>
#include <cstring>
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);
#define f first
#define s second

using namespace std;

long int N, M, inst = 1, dp[110][60];
bool marked[110][60];
pair<int, int> collection[110];

long int solve(int id, int time_left){
    if(id == M or !time_left) return 0;

    if(marked[id][time_left]) return dp[id][time_left];

    marked[id][time_left] = true;

    long int nao_coloca = solve(id + 1, time_left);

    if(collection[id].f <= time_left){
        long int coloca = collection[id].s + solve(id, time_left - collection[id].f);

        return dp[id][time_left] = max(coloca, nao_coloca);
    }
    return dp[id][time_left] = nao_coloca;

}

int main(){
    boost;

    while(cin >> N >> M, M){

        for(int i = 0; i < N; i++) cin >> collection[i].f >> collection[i].s;

        cout << "Instancia " << inst++ << endl << solve(0, M) << endl;

        memset(dp, 0, sizeof(dp) );
        memset(marked, false, sizeof(marked) );
        memset(collection, 0, sizeof(collection) );
    }

}
