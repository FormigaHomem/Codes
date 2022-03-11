#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 101010LL
#define INF 0x3f3f3f3f
#define LOG 20
#define f first
#define s second
#define lsb(x) x & (-x)
#define end "\n"

using namespace std;

typedef long long ll;

ll N, I, ans, ft[MAXN];

void update(ll x, ll limit){
    while(x <= limit){
        ft[x]++;
        x += lsb(x);
    }
}

ll sum(ll x, ll y){
    ll ret = 0;
    while(x >= y){
        ret += ft[x];
        x -= lsb(x);
    }

    return ret;
}

int main(){
    fastio

    while(cin >> I >> N){
        for(ll i = 1; i <= N; i++){
            ll p, a;
            cin >> p >> a;

            if(sum(min(p + I, MAXN), max(p - I, 1LL) ) <= a){
                update(p, min(p + I, MAXN) );
                ans++;
            }
        }

        cout << ans << endl;

        ans = 0;
        for(ll i = 1; i <= MAXN; i++) ft[i] = 0;
    }
}