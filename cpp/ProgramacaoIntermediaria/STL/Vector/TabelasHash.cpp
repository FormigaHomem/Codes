#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 101
#define INF 0x3f3f3f3f
#define LOG 20
#define f first
#define s second
#define lsb(x) x & (-x)
#define endl "\n"

using namespace std;

long T, N, M;
vector<int> v[MAXN];

int main(){
    fastio

    cin >> T;

    while(T--){
        cin >> N >> M;

        for(int i = 1; i <= M; i++){
            int x;
            cin >> x;
            v[x % N].push_back(x);
        }

        for(int i = 0; i < N; i++){
            cout << i << " -> ";
            for(auto j : v[i]) cout << j << " -> ";
            cout << "\\\n";
            v[i].clear();
        }
        if(T) cout << endl;
    }
}