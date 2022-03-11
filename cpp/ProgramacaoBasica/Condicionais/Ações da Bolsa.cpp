#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, soma;
    int somaMaior = -100000;
    
    cin >> N;
    
    int X[N];
    
    for(int i = 0; i < N; i++){
        cin >> X[i];
        if(i >= 3){
            soma = (X[i]) + (X[i - 1]) + (X[i - 2]) + (X[i - 3]);
            
            if(soma > somaMaior){
                somaMaior = soma;
            }
        }
    } 
    cout << somaMaior;
}



