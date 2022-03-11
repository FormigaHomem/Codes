#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (long) 1e4

using namespace std;

unsigned long long N, G, celula, psa[MAXN][MAXN], maior = 1;
bool ok;

int main(){_

    cin >> N >> G;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> celula;
            psa[i][j] = psa[i][j - 1] + psa[i - 1][j] + celula - psa[i - 1][j - 1];
        }
    }

    while(ok = true){

        for(int i = maior; i <= N; i += maior){
            for(int j = maior; j <= N; j += maior)
                if(psa[i][j] - psa[i][j - maior] - psa[i - maior][j] + psa[i - maior][j - maior] < G){
                    ok = false;
                    break;
                }
            if(not ok) break;
        }

        if(ok) break;
        maior *= 2;
    }

    cout << N * N / (maior * maior) << endl;
}