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

int N;
vector<pii> laptop;
vector<int> products_quality;

int main(){

    cin >> N;

    for(int i = 1; i <= N; i++){
        int x, y;
        cin >> x >> y;
        laptop.push_back( {x, y} );
    }

    sort(laptop.begin(), laptop.end() );

    for(auto i : laptop) products_quality.push_back(i.s);

    if(is_sorted(products_quality.begin(), products_quality.end() ) ) cout << "Poor Alex";
    else cout << "Happy Alex";
    
}
