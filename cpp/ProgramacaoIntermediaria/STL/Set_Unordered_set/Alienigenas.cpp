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

int main(){
    fastio

    while(cin >> N, N){
        set<vector<int> > s;

        while(N--){
            vector<int> v(15);
            string seq;
            cin >> seq;
            for(auto i : seq) v[(int) i - 'A']++;
            s.insert(v);
        }

        cout << s.size() << endl;
    }
}