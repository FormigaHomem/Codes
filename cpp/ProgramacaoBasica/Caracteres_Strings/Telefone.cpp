#include <bits/stdc++.h>
using namespace std;
int main(){
    char Telefone[15];
    
    cin >> Telefone;
    
    for(int contador; contador < 15; contador++){
        if( (Telefone[contador] == 'A') || (Telefone[contador] == 'B') || (Telefone[contador] == 'C') ){
            Telefone[contador] = '2';
        }
        if( (Telefone[contador] == 'D') || (Telefone[contador] == 'E') || (Telefone[contador] == 'F') ){
            Telefone[contador] = '3';
        }
        if( (Telefone[contador] == 'G') || (Telefone[contador] == 'H') || (Telefone[contador] == 'I') ){
            Telefone[contador] = '4';
        }
        if( (Telefone[contador] == 'J') || (Telefone[contador] == 'K') || (Telefone[contador] == 'L') ){
            Telefone[contador] = '5';
        }
        if( (Telefone[contador] == 'M') || (Telefone[contador] == 'N') || (Telefone[contador] == 'O') ){
            Telefone[contador] = '6';
        }
        if( (Telefone[contador] == 'P') || (Telefone[contador] == 'Q') || (Telefone[contador] == 'R') || (Telefone[contador] == 'S') ){
            Telefone[contador] = '7';
        }
        if( (Telefone[contador] == 'T') || (Telefone[contador] == 'U') || (Telefone[contador] == 'V') ){
            Telefone[contador] = '8';
        }
        if( (Telefone[contador] == 'W') || (Telefone[contador] == 'X') || (Telefone[contador] == 'Y') ){
            Telefone[contador] = '9';
        }
        if( (Telefone[contador] == '-') ){
            Telefone[contador] = '-';
        }
    }
       
    cout << Telefone;
}
