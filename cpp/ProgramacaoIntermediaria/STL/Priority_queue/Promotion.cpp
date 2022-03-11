#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio;(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 101010
#define INF 0x3f3f3f3
#define LOG 20
#define lsb(x) x & (-x)
#define f first
#define s second
#define endl '\n'

using namespace std;

int N;
long long ans;
multiset<int> seq;

int main(){
    fastio

    cin >> N;

    while(N--){
        int k;
        cin >> k;
        
        while(k--){
            int x;
            cin >> x;
            seq.insert(x);
        }

        ans += *(--seq.end() ) - *seq.begin();
        seq.erase(seq.begin() );
        seq.erase( (--seq.end() ) );
    }

    cout << ans << endl;
}