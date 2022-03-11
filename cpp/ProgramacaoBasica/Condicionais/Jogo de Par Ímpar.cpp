#include <bits/stdc++.h>
using namespace std;
int main(){
    int P, D_1, D_2;
    
    P == 0 || 1;
    D_1 >= 0 && D_1 <= 5;
    D_2 >= 0 && D_2 <= 5;
    
    cin >> P >> D_1 >> D_2;
    
    switch(P){
        case 0:
        if( ( (D_1 + D_2) % 2) == 0){
            cout << 0;
        }
        else{
            cout << 1;
        }
        break;
        case 1:
         if( ( (D_1 + D_2) % 2) == 0){
            cout << 1;
        }
        else{
            cout << 0;
        }
        break;
    }
}