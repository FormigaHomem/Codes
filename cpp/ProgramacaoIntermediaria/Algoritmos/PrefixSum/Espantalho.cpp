#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e4 + 10

using namespace std;

long long N, M, psa[MAXN][MAXN], cajus, is_possible;

int main(){_

    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> cajus;
            psa[i][j] = psa[i][j - 1] + psa[i - 1][j] - psa[i - 1][j - 1] + cajus;
        }
	}

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            long long q1 = psa[i][j], q2 = psa[i][M] - psa[i][j], q3 = psa[N][j] - psa[i][j], q4 = psa[N][M] - psa[N][j] - psa[i][M] + psa[i][j];
            if(q1 == q2 and q1 == q3 and q1 == q4){
				cout << i << " " << j << endl;
				is_possible = 1;
			}
        }
	}

	if(!is_possible) cout << -1 << endl;
}