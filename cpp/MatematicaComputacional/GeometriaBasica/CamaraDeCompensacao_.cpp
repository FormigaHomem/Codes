#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (long) 1e3 + 10

using namespace std;

int M, N, X, V, Y, total, debito, credito[MAXN];

int main(){

    cin >> M >> N;

    for(int i = 1; i <= M; i++){
        cin >> X >> V >> Y;
        credito[X] -= V;
        credito[Y] += V;
        total += V;
    }

    for(int i = 1; i <= N; i++)
        if(credito[i] < 0) debito -= credito[i];

    if(debito == total) cout << "N\n" << total << endl;
    else cout << "S\n" << debito << endl;
}