#include <iostream>
#include <algorithm>

using namespace std;

bool BuscaBinaria(int a, int b, long int v[], int c){
    int m;
    while(a <= b){
        m = (a + b) / 2;
        if(v[m] == c){
            return true;
        }
        else{
            if(v[m] > c) b = m - 1;
            else a = m + 1;
        }
    }
    return false;
}

int main(){
    int N, k;

    cin >> N;

    long int A[N + 5];

    for(int i = 0; i < N; i++) cin >> A[i];

    cin >> k;

    for(int i = 0; i < N; i++){
        int a = A[i];
        if(BuscaBinaria(0, N - 1, A, k - a)){
            cout << a << " " << k - a;
            return 0;
        }
    }

}
