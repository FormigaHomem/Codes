#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

long long N, P, Q, R, S, X, Y, x, y, sum;

int main(){_

    cin >> N >> P >> Q >> R >> S >> X >> Y >> x >> y;
    
    for(int k = 1; k <= N; k++) sum += ( (x * P + k * Q) % X) * ( (k * R + y * S) % Y);

    cout << sum << endl;
}