#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 5 * (int) 1e4 + 10

using namespace std;

int N, sala[MAXN], prefix_sum[MAXN], mais_vida = MAXN * 100;

int main(){

    cin >> N;

    for(int i = 1; i <= N; i++) cin >> sala[i];

    mais_vida *= -1;
    for(int i = 1; i <= N; i++){
        prefix_sum[i] = max(prefix_sum[i - 1] + sala[i], 0);
        mais_vida = max(mais_vida, prefix_sum[i]);
    }

    cout << mais_vida << endl;
}