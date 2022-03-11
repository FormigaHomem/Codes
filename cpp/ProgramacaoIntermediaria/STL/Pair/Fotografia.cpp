#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 2e2 + 10
#define f first
#define s second

using namespace std;

long a, l, N, area;
pair<int, int> photograph;
pair<int, pair<int, int> > ans;

int main(){_

    cin >> photograph.f >> photograph.s >> N;

    ans = {-1, {MAXN, MAXN} };
    area = photograph.f * photograph.s;
    for(int i = 1; i <= N; i++){
        cin >> a >> l;
        if( (a >= photograph.f and l >= photograph.s) or (l >= photograph.f and a >= photograph.s) ){
            pair<int, int> temp = (pair<int, int>) {a - photograph.f, l - photograph.s} < (pair<int, int>) {l - photograph.f, a - photograph.s}? pair<int, int>(a, l) : pair<int, int>(l, a);
            if(temp.f * temp.s - area < ans.s.f * ans.s.s - area) ans = {i, temp};
        }
    }

    cout << ans.f << endl;
}