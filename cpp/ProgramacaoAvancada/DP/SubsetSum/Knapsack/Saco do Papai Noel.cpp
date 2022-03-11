#include <iostream>
#include <map>
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

map<pair<int, long int>, long int> dp;
map<pair<int, long int>, bool> marked;
long int N, M;
pair<long int, int> object[110];

long int solve(int id, long int aguenta){
    if(id == N or !aguenta) return 0;
    if(marked[{id, aguenta}]) return dp[{id, aguenta}];

    marked[{id, aguenta}] = true;

    long int nao_coloca = solve(id + 1, aguenta);

    if(object[id].first <= aguenta){
        long int coloca = object[id].second + solve(id + 1, aguenta - object[id].first);

        return dp[{id, aguenta}] = max(nao_coloca, coloca);
    }
    return dp[{id, aguenta}] = nao_coloca;

}

int main(){
    boost;

    cin >> N >> M;

    for(int i = 0; i < N; i++) cin >> object[i].first >> object[i].second;

    cout << solve(0, M);

}
