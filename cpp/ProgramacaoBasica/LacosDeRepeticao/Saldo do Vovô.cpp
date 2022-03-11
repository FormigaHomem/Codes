#include <bits/stdc++.h>
using namespace std;

int main(){

    int N, S, menor;

    cin >> N >> S;

    int dp[N];
    menor = 1005;

    for(int i = 1; i <= N; i++){
        cin >> dp[i - 1];
        S += dp[i - 1];

        if(i > 0 && S <= menor){
            menor = S;
        }
    }

    cout << menor;

}
