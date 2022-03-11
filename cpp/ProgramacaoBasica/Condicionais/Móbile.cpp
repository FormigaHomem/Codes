#include <bits/stdc++.h>
using namespace std;
int main(){
    int A, B, C, D;

    cin >> A >> B >> C >> D;

    if( (A == B + C + D) && (D == B + C) && (B == C) ){
        cout << "S";
    }
    else{
        cout << "N";
    }

}

