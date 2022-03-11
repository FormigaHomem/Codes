#include <iostream>
#include <algorithm>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, pair<ll, ll> > pii;

long int N, M, dp[10010][697][5];
bool marked[10010][697][5];
pii loot[10010];

bool ord(pii a, pii b){
    return a.s.s > b.s.s;
}

ll solve(ll id, int aguenta, int gains){
    if(id == N or !aguenta) return 0;

    if(marked[id][aguenta][gains]) return dp[id][aguenta][gains];

    marked[id][aguenta][gains] = true;

    ll nao_coloca = solve(id + 1, aguenta, gains);

    if( ( (loot[id].s.f - loot[id].s.s) <= aguenta and gains < 2) or (loot[id].s.f <= aguenta) ){
        ll coloca_e_usa = -1, coloca_e_nn_usa = -1;
        if( (loot[id].s.f - loot[id].s.s) <= aguenta and gains < 2) coloca_e_usa = loot[id].f + solve(id + 1, aguenta - (loot[id].s.f - loot[id].s.s), gains + 1);
        if(loot[id].s.f <= aguenta) coloca_e_nn_usa = loot[id].f + solve(id + 1, aguenta - loot[id].s.f, gains);

        return dp[id][aguenta][gains] = max(nao_coloca, max(coloca_e_nn_usa, coloca_e_usa) );
    }
    return dp[id][aguenta][gains] = nao_coloca;

}

int main(){_

    cin >> N >> M;

    for(int i = 0; i < N; i++) cin >> loot[i].f >> loot[i].s.f >> loot[i].s.s;

    sort(loot, loot + N, ord);

    cout << solve(0, M, 0) << endl;
}
