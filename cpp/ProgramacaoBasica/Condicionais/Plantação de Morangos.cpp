#include <bits/stdc++.h>
using namespace std;
int main(){
    int C1, L1, C2, L2;

    cin >> C1;
    cin >> L1;
    cin >> C2;
    cin >> L2;

    if( (C1 * L1) > (C2 * L2) ){
        cout << C1 * L1;
    }
    else{
        cout << C2 * L2;
    }
}
