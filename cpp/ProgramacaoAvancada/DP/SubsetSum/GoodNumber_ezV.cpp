#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e4 + 10

using namespace std;

typedef long long ll;

ll q, N, num = 3;
vector<ll> power;

ll ans(ll sum, ll id){

    if(sum <= 0) return N - sum;

    ll resp = 0;
    for(ll p = id; p < power.size(); p++)
        resp = (resp? min(resp, ans(sum - power[p], p + 1) ) : max(0LL, ans(sum - power[p], p + 1) ) );

    return resp;
}

int main(){_
    
    power.push_back(1);
    while(num <= (long) 1e5){
        power.push_back(num); 
        num *= 3;
    }

    cin >> q;

    while(q--){
        cin >> N;

        cout << ans(N, 0) << endl;
    }

}