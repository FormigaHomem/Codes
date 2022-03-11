#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, Menor, B;
    
    cin >> N;
    
    for(int contador = 0; contador < N; contador++){
        cin >> B;
        if(contador == 0){
            Menor = B;
        }
        if(B < Menor){
            Menor = B;
        }
    }
    cout << Menor;
}