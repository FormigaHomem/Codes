#include <iostream>

using namespace std;

int main(){

    int L, C, L1, L2, C1, C2, a, b;

    cin >> L1 >> L2 >> C1 >> C2;

    L = L1 + L2;
    C = C1 + C2;

    if(L1 == L2) L *= 2;
    else if(L1 + 1 == L2 or L2 + 1 == L1) L *= 3;

    if(C1 == C2) C *= 2;
    else if(C1 + 1 == C2 or C2 + 1 == C1) C *= 3;

    cout << (L != C? (L > C? "Lia" : "Carolina") : "empate" );

}
