#include <bits/stdc++.h>
using namespace std;
int main(){

    int A, B, C, X, Y, Z;

    cin >> A >> B >> C;

    cin >> X >> Y >> Z;

    if(A <= X && B <= Y && C <= Z){
        cout << (X / A) * (Y / B) * (Z / C);
    }
    else{
        cout << 0;
    }

}
