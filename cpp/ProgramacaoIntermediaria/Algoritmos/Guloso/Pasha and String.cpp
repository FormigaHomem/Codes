#include <iostream>

using namespace std;

int main(){

    string a;
    int M;

    cin >> a >> M;

    int tam = a.size(), A[tam + 5] = {0}, x;

    for(int i = 0; i < M; i++){
        cin >> x;
        x--;
        A[x]++;
    }
    for(int i = 0; 2 * i < tam; i++){
        if(i) A[i] += A[i - 1];
        if(A[i] & 1) swap(a[i], a[tam - i - 1]);
    }
    cout << a;
}
