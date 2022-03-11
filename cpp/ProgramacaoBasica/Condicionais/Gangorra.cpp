#include <bits/stdc++.h>
using namespace std;
int main(){
    float P1, C1, P2, C2;
    
    P1 >= 10 && P1 <= 100 && C1 >= 10 && C1 <= 100; 
    P2 >= 10 && P2 <= 100 && C2 >= 10 && C2 <= 100;
    
    cin >> P1 >> C1 >> P2 >> C2;
    
    if( (P1 * C1) == (P2 * C2) ){
        cout << "0";
    }
    else{
        if( (P1 * C1) != (P2 * C2) && (P1 * C1) > (P2 * C2) ){
            cout << "-1";
        }
        else{
            cout << "1";
        }
    }
}