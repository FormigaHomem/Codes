#include <bits/stdc++.h>

using namespace std;

int main(){

    int B, T, Af, Am;

    cin >> B >> T;

    Af = ( (B + T) * 70) / 2;
    Am = ( (160 - B + (160 - T) ) * 70) / 2;

    if(Af > Am) cout << 1;
    else if(Am > Af) cout << 2;
    else cout << 0;
}