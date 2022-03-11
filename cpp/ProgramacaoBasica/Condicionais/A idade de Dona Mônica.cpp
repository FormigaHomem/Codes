#include <bits/stdc++.h>
using namespace std;
int main(){
    int M, A, B, C;
    
    cin >> M >> A >> B;
    
    C = M - (A + B);
    
    if(A > B && A > C){
        cout << A;
    }
    if(B > A && B > C){
        cout << B;
    }
    if(C > A && C > B){
        cout << C;
    }
}
