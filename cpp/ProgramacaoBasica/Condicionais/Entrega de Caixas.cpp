#include <bits/stdc++.h>
using namespace std;
int main(){

    int A, B, C;

    cin >> A >> B >> C;

    if(A == B && B == C && A == C){
        cout << 3;
    }
    else if(A == B && A != C){

        if((A + B) < C){
            cout << 1;
        }
        else{
           cout << 2;
        }
    }
    else if(A == C && A != B){
        if((A + C) < B){
            cout << 1;
        }
        else{
           cout << 2;
        }
    }
    else if(C == B && C != A){
        if( (C + B) < A){
            cout << 1;
        }
        else {
           cout << 2;
        }
    }
    else if(A != B && B != C && A != C){
        cout << 1;
    }

}
