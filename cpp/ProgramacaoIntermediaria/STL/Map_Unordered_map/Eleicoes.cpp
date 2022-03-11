#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 101010
#define INF 0x3f3f3f3f
#define LOG 20
#define f first
#define s second
#define lsb(x) & (-x)
#define endl "\n"

using namespace std;

typedef long long ll;

long N;
map<ll, ll> m;

int main(){
    fastio

    cin >> N;

    m[0] = -1;
    auto ans = m.begin();

    while(N--){
        ll x;
        cin >> x;

        m[x]++;
        if(m[x] > ans->s) ans = m.find(x);
    }

    cout << ans->f << endl;
}