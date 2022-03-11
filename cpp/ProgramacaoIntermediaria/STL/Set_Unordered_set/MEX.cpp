#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 401010
#define INF 0x3f3f3f3f
#define LOG 20
#define lsb(x) x & (-x)
#define f first
#define s second
#define endl '\n'

using namespace std;

int q, x;
long long num;
set<long long> s;
vector<long long> mod;

int main(){
    fastio

    cin >> q >> x;

    for(int i = 0; i < x; i++){
        mod.push_back(i);
        s.insert(i);
    }

    while(q--){
        cin >> num;
        int curr = num % x;

        s.erase(mod[curr]);
        mod[curr] += x;
        s.insert(mod[curr]);
        
        cout << *s.begin()<< endl;
    }
}