#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define f first
#define s second
#define lsb(x) x & (-x)
#define INF 0x3f3f3f3f
#define LOG 20
#define MAXN 101010

using namespace std;

long N, M, ans, v[MAXN], ft[MAXN];

void update(int x){
    while(x < N){
        ft[x]++;
        x += lsb(x);
    }
}

long sum(int x){
    long ret = 0;

    while(x > 0){
        ret += ft[x];
        x -= lsb(x);
    }

    return ret;
}

int main(){_

    cin >> N >> M;

    ans = N;

    for(int i = 1; i <= M; i++){
        cin >> v[i];

        update(v[i]);

        if(ans == N and sum(v[i]) > v[i]) ans = i;
    }

    cout << ans << endl;
}