#include <bits/stdc++.h>

using namespace std;

int t, n;

int main(){

    cin >> t;

    while(t--){
        cin >> n;
        int ans[200], reset = 1, last;
        for(int i = 1; i <= n; i++){
            if(n - i + reset == i){
                reset = 0;
                cout << n - i << " ";
                last = n - i + 1;
                continue;
            }
            cout << (n - i + reset? n - i + reset : last) << " ";
        }
        cout << endl;
    }
}