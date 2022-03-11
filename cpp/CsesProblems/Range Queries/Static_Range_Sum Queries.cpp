#include <bits/stdc++.h>
 
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (long) 2e5
#define sz(x) (int) x.size() 
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pll;
 
ll N, Q;
vector<ll> prefix, v;
 
// build: O(N)
void build(){
    prefix.assign(N + 1, 0);
 
    for(int i = 1; i <= N; i++)
        prefix[i] = v[i] + prefix[i - 1]; 
}
 
// query: O(1)
ll query(int l, int r){
    return prefix[r] - prefix[l - 1];
}
 
int main(){_
 
    cin >> N >> Q;
 
    v.resize(N + 1);
 
    for(int i = 1; i <= N; i++) cin >> v[i];
 
    build();
 
    while(Q--){
        int a, b;
        cin >> a >> b;
 
        cout << query(a, b) << "\n";
    }
}
