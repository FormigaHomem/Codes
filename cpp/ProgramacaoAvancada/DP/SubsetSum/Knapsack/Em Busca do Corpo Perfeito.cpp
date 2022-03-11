#include <iostream>
#define ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

long int P, N, dp[2010][2010];
pair<int, int> carne[2010];
bool marked[2010][2010];

long int solve(int id, int aguenta){
    //Casos base.
    if(!aguenta  or id == N) return 0;
    if(marked[id][aguenta]) return dp[id][aguenta];

    marked[id][aguenta] = true;
    int nao_come = solve(id + 1, aguenta);

    if(carne[id].first <= aguenta){
        int come = carne[id].second + solve(id + 1, aguenta - carne[id].first);

        return dp[id][aguenta] = max(come, nao_come);
    }
    return dp[id][aguenta] = nao_come;

}

int main(){



    cin >> P >> N;

    for(int i = 0; i < N; i++) cin >> carne[i].first >> carne[i].second;

    cout << solve(0, P);

}
