#include <bits/stdc++.h>
using namespace std;

int main(){

    int N, maior = 0;

    do{
        cin >> N;
        if(maior < N){
            maior = N;
        }
    }while(N != 0);

    cout << maior;

}
