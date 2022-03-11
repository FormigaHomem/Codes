#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (long) 1e5 + 10

set<long> bridge[MAXN];
long N, M, call, a, b;

int main(){_

    cin >> N >> M;

    while(M--) {
        cin >> call >> a >> b;

        if(!call) {
            if(bridge[a].find(b) != bridge[a].end() ) cout << 1 << endl;
            else cout << 0 << endl;
        }

        else{
            bridge[a].insert(b);
            bridge[b].insert(a);
        }
    }
}
