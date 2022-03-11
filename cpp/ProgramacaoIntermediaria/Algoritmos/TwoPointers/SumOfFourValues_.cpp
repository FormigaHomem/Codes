#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e3 + 10
#define ll long long
#define f first
#define s second

using namespace std;

ll N, x, curr1, curr2, l, r, soma;
pair<ll, ll> num[MAXN];
int main(){

    cin >> N >> x;

    for(int i = 1; i <= N; i++){
        cin >> num[i].f;
        num[i].s = i;
    }

    sort(num + 1, num + N + 1);

    for(int i = 1; i <= N - 3; i++){
        if(num[i].f == num[i - 1].f) continue;
        for(int j = i + 1; j <= N - 2; j++){
            curr1 = i;
            curr2 = j;
            l = j + 1;
            r = N;

            while(l < r){
                soma = num[curr1].f + num[curr2].f + num[l].f + num[r].f;
                if(soma == x){
                    cout << num[curr1].s << " " << num[curr2].s << " " << num[l].s << " " << num[r].s << endl;
                    return 0;
                }

                if(soma < x) l++;
                else r--;
            }

        }
    }

    cout << "IMPOSSIBLE\n";
}