#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define f first
#define s second
#define lsb(x) x & (-x)
#define INF 0x3f3f3f3f
#define LOG 20
#define MAXN (int) 1e9 + 10

using namespace std;

long N, M, t;
vector<int> seq;

int main(){_

    cin >> N >> M;

    for(int i = 0; i <= N; i++) seq.push_back(i);

    for(int i = 1; i <= M; i++){
        cin >> t;

        long long l = t, r =  2 * t, removed = 0;

        while(l - removed < seq.size() ){
            seq.erase(seq.begin() + l - removed++);
            if(r - removed < seq.size() ) seq.erase(seq.begin() + r - removed++);

            l += 2 * t;
            r += 2 * t;
        }
    }

    seq.erase(seq.begin() );
    for(auto i : seq) cout << i << endl;
}