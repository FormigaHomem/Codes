#include <iostream>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e5 + 10

using namespace std;

int N, M, barra[MAXN], prefix_sum[MAXN][15], l = 1, r, appeared[15];

int main(){_

    cin >> N >> M;

    for(int i = 1; i <= N; i++) cin >> barra[i];

    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= 9; j++) prefix_sum[i][j] = prefix_sum[i - 1][j];
        prefix_sum[i][barra[i] ]++;
    }

    
    

    for(int i = 0; i < M; i++){
        cin >> r;


        int aux = r;
        if(l > r) {
            swap(l, r);
            r--;
            l--;
        }

        if(l == 1 and aux == r)
            for(int j = 0; j <= 9; j++) {
                appeared[j] += prefix_sum[r][j];
                if(j == barra[1] and aux == r and i) appeared[barra[1] ]--;
            }

        else
            for(int j = 0; j <= 9; j++) appeared[j] += prefix_sum[r][j] - prefix_sum[l][j];
                
        l = aux;
    }

    for(int i = 0; i <= 9; i++) cout << appeared[i] << " ";
}