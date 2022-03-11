#include <iostream>
#include <cstring>
#define ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int P, N, n = 1;
long int dp[2010][2010];
pair<long int, long int> frase[2010];

long int solve(int id, int tem_espaco){
    //Casos base.
    if(!tem_espaco  or id == N) return 0;
    if(dp[id][tem_espaco] != -1) return dp[id][tem_espaco];

    int nao_usa = solve(id + 1, tem_espaco);

    if(frase[id].first <= tem_espaco){
        int usa = frase[id].second + solve(id + 1, tem_espaco - frase[id].first);

        return dp[id][tem_espaco] = max(usa, nao_usa);
    }
    return dp[id][tem_espaco] = nao_usa;

}

int main(){
    while(cin >> P >> N, N){
        memset(dp, -1, sizeof(dp) );

        for(int i = 0; i < N; i++) cin >> frase[i].first >> frase[i].second;

        cout << "Teste " << n++ << endl << solve(0, P) << endl;
    }

}
