#include <iostream>

using namespace std;

long int N, M, dp[110][100010];
bool marked[110][100010];
pair<int, int> object[110];

int solve(int id, int aguenta){
    if(id == N or aguenta <= 0) return dp[id][aguenta] = 0;
    if(marked[id][aguenta]) return dp[id][aguenta];

    marked[id][aguenta] = true;

    int nao_coloca = solve(id + 1, aguenta);

    if(object[id].first <= aguenta){
        int coloca = object[id].second + solve(id + 1, aguenta - object[id].first);

        return dp[id][aguenta] = max(nao_coloca, coloca);
    }
    return dp[id][aguenta] = 0;

}

int main(){

    cin >> N >> M;

    for(int i = 0; i < N; i++) cin >> object[i].first >> object[i].second;

    cout << solve(0, M);

}
