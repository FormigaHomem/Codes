#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 101010
#define INF 0x3f3f3f3f
#define LOG 20
#define f first
#define s second
#define lsb(x) x & (-x)
#define endl "\n"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

int N;
map<int, string> m;

int main(){
    fastio

    while(cin >> N){
        for(int i = 1; i <= N; i++){
            string a; int b;
            cin >> a >> b;
            m[b] = a;
        }

        for(auto it = m.begin(); it != m.end(); it++) cout << (it == --m.end()? it->s : it->s + " ");
        cout << endl;
        m.clear();
    }
}