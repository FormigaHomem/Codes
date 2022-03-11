#include <bits/stdc++.h>
using namespace std;
int main(){
    int D;
    
    D >=0 && D <= 2000;
    
    cin >> D;
    
    if(D <= 800){
        cout << 1;
    }
    if(D > 800 && D <= 1400){
        cout << 2;
    }
    if(D > 1400 && D <= 2000){
        cout << 3;
    }
}
