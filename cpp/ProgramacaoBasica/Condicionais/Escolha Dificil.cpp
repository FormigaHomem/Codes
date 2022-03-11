#include <iostream>

using namespace std;

int main(){

    int C1, B1, P1, C, B, P, r = 0;

    cin >> C1 >> B1 >> P1 >> C >> B >> P;

    if(C1 < C) r += C - C1;
    if(B1 < B) r += B - B1;
    if(P1 < P) r += P - P1;

    cout << r;

}
