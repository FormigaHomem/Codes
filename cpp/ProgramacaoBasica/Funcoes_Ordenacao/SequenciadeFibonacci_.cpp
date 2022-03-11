#include <bits/stdc++.h>

using namespace std;

int N, fibonacci[20];

int Fibo(int index){
    if(index == 0) return fibonacci[index] = 0;
    else if(index == 1) return fibonacci[index] = 1;

    return fibonacci[index] = Fibo(index - 1) + Fibo(index - 2);
}

int main(){

    cin >> N;

    Fibo(N);

    for(int i = 0; i < N; i++) cout << fibonacci[i] << " ";
}