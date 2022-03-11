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

typedef pair<int, int> pii;

int T, N, K;
vector<pii> presentes;

int main(){
    fastio

    cin >> T;

    while(T--){
        cin >> N >> K;

        for(int i = 1; i <= N; i++){
            int ID, H, W, L;
            cin >> ID >> H >> W >> L;
            presentes.push_back( {H * W * L, ID} );
        }

        sort(presentes.begin(), presentes.end(), [] (pii a, pii b) { return (a.f != b.f? a.f > b.f : a.s < b.s);} );
        sort(presentes.begin(), presentes.begin() + K, [] (pii a, pii b) { return a.s < b.s;});

        for(int i = 0; i < K; i++){
            if(i != K - 1) cout << presentes[i].s << " ";
            else cout << presentes[i].s << endl;
        }

        presentes.clear();
    }
}