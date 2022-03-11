#include <iostream>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e5 + 10

using namespace std;

int N, T, cima[MAXN], baixo[MAXN], ind1, ind2, prefix_sum[MAXN], op[MAXN];

int main(){_

    cin >> N >> T;

    for(int i = 1; i <= N; i++) cin >> cima[i];
    for(int i = 1; i <= N; i++) cin >> baixo[i];

    for(int i = 0; i < T; i++){
        cin >> ind1 >> ind2;
        op[ind1]++; op[ind2 + 1]--;
    }

    for(int i = 1; i <= N; i++) prefix_sum[i] = prefix_sum[i - 1] + op[i];

    for(int i = 1; i <= N; i++) cout << (prefix_sum[i] % 2 == 1? baixo[i] : cima[i]) << " ";
}
