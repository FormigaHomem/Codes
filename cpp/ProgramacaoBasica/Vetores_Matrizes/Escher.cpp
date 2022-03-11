#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, n  = 0;

    cin >> N;


    int A[N], V[N];

    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int j = N - 1; j >= 0; j--){
        V[n] = A[j];
        n++;
    }
    n = 0;
    for(int i = 1; i <= N / 2; i++){
        if( (A[i - 1] + V[i - 1]) == (A[i] + V[i]) ){
            n++;
        }
    }
    if(n == (N / 2) ){
        cout << 'S';
    }
    else{
        cout << 'N';
    }

}
