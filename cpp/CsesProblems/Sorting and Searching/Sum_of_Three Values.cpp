#include <bits/stdc++.h>
 
#define MAXN (int) 6e3
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
ll N, x, a, curr, l, r, soma;
pair<ll, ll>  num[MAXN];
 
int main(){_
 
    cin >> N >> x;
 
    for(int i = 1; i <= N; i++) {
        cin >> num[i].f;
        num[i].s = i;
    }
 
    sort(num + 1, num + N + 1);
 
    for(int i = 1; i <= N - 2; i++){
        if(num[i].f == num[i - 1].f) continue;
        curr = i;
        l = i + 1;
        r = N;
        while(l < r){
            soma = num[curr].f + num[l].f + num[r].f;
             if(soma == x){
                cout << num[curr].s << " " << num[l].s << " " << num[r].s << endl;
                return 0;
             }
 
             if(soma < x) l++;
             else r--;
        }
    }
 
    cout << "IMPOSSIBLE\n";
}
