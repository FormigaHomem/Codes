#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 101010
#define INF 0x3f3f3f3
#define LOG 20
#define f first
#define s second
#define lsb(x) x & (-x)
#define endl "\n"

using namespace std;

long long N, ft[MAXN], pos[MAXN], ans;

void update(int x, int k){
    while(x > 0){
        ft[x] += k;
        x -= lsb(x);
    }
}

long long sum(int x){
    long long ret = 0;
    while(x <= N){
        ret += ft[x];
        x += lsb(x);
    }

    return ret;
}

int main(){
    fastio

    while(cin >> N){
        for(int i = 1; i <= N; i++){
            int id;
            cin >> id;
            pos[id] = i;
            update(pos[id], 1);
        }

        for(int i = 1; i <= N; i++){
            ans += sum(pos[i] + 1);
            update(pos[i], -1);
        }

        cout << ans << endl;
        ans = 0;
        for(int i = 1; i <= N; i++) ft[i] = 0;
    }
}