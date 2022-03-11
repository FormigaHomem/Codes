#include <iostream>

using namespace std;

int main(){

    int N, cem = 0;

    cin >> N;

    int A[N + 5];

    for(int i = 0; i < N; i++) cin >> A[i];

    for(int i = 0; i < N - 2; i++)
        if(A[i])
            if(!A[i + 1] && !A[i + 2]) cem++;

    cout << cem;

}
