#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 101010
#define INF 0x3f3f3f3f
#define LOG 20
#define endl '\n'
#define lsb(x) x & (-x)
#define f first
#define s second

using namespace std;

int N;
vector<int> toys;

int main(){

    cin >> N;

    for(int i = 1; i <= N; i++){
        int x;
        cin >> x;
        toys.push_back(x);
    }

    sort(toys.begin(), toys.end() );

    for(auto i : toys) cout << i << " ";
}