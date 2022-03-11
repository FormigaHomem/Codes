#include <bits/stdc++.h> 
using namespace std;
int main(){
    int contador, N, L, C, acumulador;
    contador=1;
    N>=1 and N<=100;
    L>=1 and L<=100;
    C>=1 and C<=100;
    cin >> N;
    acumulador = 0;
    while(contador<=N){
        cin >> L >> C;
        contador=contador+1;
        if(L>C){
            acumulador = acumulador + C;
        }
    }
    cout << acumulador;
}
  