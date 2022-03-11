#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (long) 1e3 + 10
#define f first
#define s second

using namespace std;

long L, C, matriz[MAXN][MAXN], sub_matrixes[MAXN][MAXN], height[MAXN][MAXN], l[MAXN], r[MAXN], base, ans, aux;

int main(){

    cin >> L >> C;

    //Getting the matrix
    for(int i = 1; i <= L; i++)
        for(int j = 1; j <= C; j++)
            cin >> matriz[i][j];

    // Compacting the matrix into two sized sub-matrixes and marking them if they're cool. Also making the histogram.
    for(int i = 2; i <= L; i++)
        for(int j = 2; j <= C; j++){
            
            if(matriz[i - 1][j - 1] + matriz[i][j] <= matriz[i - 1][j] + matriz[i][j - 1]){
                sub_matrixes[i - 1][j - 1] = 1;
                height[i - 1][j - 1] = 1 + height[i - 2][j - 1];
            }
        }
    
    //
    for(int j = 1; j < L; j++){
        aux = 0; height[j][0] = height[j][C] = -1;

        //Get the first number lower than i from left to right.
        for(int i = 1; i < C; i++){
            l[i] = i - 1;
            while(height[j][l[i] ] >= height[j][i]) l[i] = l[l[i] ];
        }

        //Get the first number lower than i from right to left.
        for(int i = C - 1; i >= 1; i--){
            r[i] = i + 1;
            while(height[j][r[i] ] >= height[j][i]) r[i] = r[r[i] ];
        }

        //Get the base of the greater rectangle with i's height. Then get the area of this same rectangle.
        for(int i = 1; i < C; i++){
            base = r[i] - l[i] - 1;
            aux = max(aux, (base + 1) * (height[j][i] + 1) );
        }

        ans = max(ans, aux);
    }

    cout << ans << endl;
}