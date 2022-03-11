// idea 1: use prefix_sum to get the max influency. Success
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (long) 5e5 + 10

using namespace std;

long N, FI, prefix_sum[MAXN], ans;

int main(){_

    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> FI;
        prefix_sum[1]++; prefix_sum[min( (long) 5e5 + 10, FI + 1) ]--;
    }

    long current_sum = 0;
    for(int i = 1; i <= N; i++){
        current_sum += prefix_sum[i];
        if(current_sum >= i) ans = i;
    }
    
    cout << ans << endl;
}