#include <bits/stdc++.h>

#define MAXN (int) 1e5 + 10

using namespace std;

int main(){

    long long int N, K, num[MAXN];

    cin >> N;

    for(int i = 1; i <= N; i++) cin >> num[i];

    cin >> K;

    int l = 1, r = N;
    while(l < r){
        if(num[l] + num[r] == K){
            cout << num[l] << " " << num[r] << endl;
            return 0; 
        }

        if(num[l] + num[r] < K) l++;
        else r--;
    }

}