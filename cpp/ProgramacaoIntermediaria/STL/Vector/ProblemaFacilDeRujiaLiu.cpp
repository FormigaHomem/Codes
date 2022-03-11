#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 101010
#define INF 0x3f3f3f3f
#define LOG 20
#define f first
#define s second
#define lsb(x) X & (-x)
#define endl "\n"

using namespace std;

long N, M, v[MAXN];
map<int, vector<int> > m;

int main(){
    fastio

    while(cin >> N >> M){

        for(int i = 1; i <= N; i++){
            cin >> v[i];
            m[v[i] ].push_back(i);
        }

        while(M--){
            int k, x;
            cin >> k >> x;
            
            if(m.find(x) != m.end() and m[x].size() >= k) cout << m[x][k - 1] << endl;
            else cout << 0 << endl;
        }

        m.clear();
    }
}