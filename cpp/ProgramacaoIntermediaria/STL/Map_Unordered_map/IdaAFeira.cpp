#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 101010
#define INF 0x3f3f3f3f
#define LOG 20
#define f first
#define s second
#define lsb(x) x & (-x)
#define endl "\n"

using namespace std;

long T, N, M;
float ans;
map<string, float> cost;

int main(){
    fastio

    cin >> T;

    while(T--){
        cin >> N;

        while(N--){
            string product; float price;
            cin >> product >> price;

            cost[product] = price;
        }

        cin >> M;

        while(M--){
            string product; float quantity;
            cin >> product >> quantity;

            ans += cost[product] * quantity;
        }

        cout.precision(2);
        cout << "R$ " << fixed << ans << endl;
        ans = 0; cost.clear();
    }
}