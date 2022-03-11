#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 101010
#define INF 0x3f3f3f3f
#define LOG 20
#define f first
#define s second
#define lsb(x) x & (-x)
#define endl '\n'

using namespace std;

int N;
set<int> s;

int main(){
    fastio

    cin >> N;
    
    while(N--){
        int x;
        cin >> x;
        s.insert(x);
    }

    cout << s.size() << endl;
}