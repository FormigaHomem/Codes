#include <iostream>

using namespace std;

int main(){

    long long int n, k, m;

    cin >> n >> k >> m;

    long long int a[n + 5], f[k + 5] = {0};

    for(long long int i = 0; i < n; i++) cin >> a[i];
    for(long long int i = 0; i < n; i++) cin >> f[i];

    if(k <= n) {
        cout << f[k - 1];
        return 0;
    }
    for(long long int i = n; i < k; i++)
        for(long long int j = 0; j < n; j++)
            f[i] = (f[i] + a[j] * f[i - (j + 1)]) % m;

    cout << f[k - 1];

}
