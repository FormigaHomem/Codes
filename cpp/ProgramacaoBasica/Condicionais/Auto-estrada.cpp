#include <bits/stdc++.h>
using namespace std;
int main(){
    int c, acumulador;
    char P, C, A, D, N;
    
    cin >> c;
    
    acumulador = 0;
    for(int contador = 0; contador < c;){
        cin >> N;
        contador = contador + 1;
        switch(N){
            case 'P':
            N = 2;
            break;
            case 'C':
            N = 2;
            break;
            case 'A':
            N = 1;
            break;
            case 'D':
            N = 0;
            break;
            default:
            N = 0;
            break;
        }
        acumulador = acumulador + N;
    }
    
    cout << acumulador;
        
}