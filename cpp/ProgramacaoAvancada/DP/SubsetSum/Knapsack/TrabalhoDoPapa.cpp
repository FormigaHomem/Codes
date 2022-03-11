#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
#define MAXN (int) 1e3
#define f first
#define s second

using namespace std;

typedef pair<long, long> pll;

vector<pll> caixa;
long N, P, R;
pll dp[MAXN], a = {-1, -1};

long ans(int id, long peso){
    if(id == N) return 0;

    if(dp[id] != a and dp[id].s == peso) return dp[id].f;

    long nao_coloca = ans(id + 1, peso);

    if(caixa[id].s - caixa[id].f >= peso){
        long coloca = 1 + ans(id + 1, peso + caixa[id].f);
        dp[id] = {max(coloca, nao_coloca), peso};
        return dp[id].f;
    }

    dp[id] = {nao_coloca, peso};
    return dp[id].f;
}

int main(){_
    memset(dp, -1, sizeof(dp) );

    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> P >> R;
        if(P <= R) caixa.emplace_back(P, R);
    }

    sort(caixa.begin(), caixa.end(), [] (pll a, pll b) {return a.s - a.f < b.s - b.f;} );

    cout << ans(0, 0) << endl;
}