#include <bits/stdc++.h>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 101010
#define LOG 20
#define INF 0x3f3f3f3f
#define f first
#define s second
#define lsb(x) x & (-x)
#define endl '\n'

using namespace std;

int N, M;
vector<pair<int, int> > pilot;

int main(){
 
    cin >> N >> M;
    pilot.resize(N + 1);

    for(int i = 1; i <= N; i++){
        int x;
        for(int j = 1; j <= M; j++){
            cin >> x;
            pilot[i] = {pilot[i].f + x, i};
        }
    }
    sort(pilot.begin(), pilot.end() );

    for(int i = 1; i <= 3; i++) cout << pilot[i].s << endl;
}