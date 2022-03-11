#include <bits/stdc++.h>

using namespace std;

int main(){
    float Pa, Pg, Ra, Rg;

    cin >> Pa >> Pg >> Ra >> Rg;

    cout << ( (Ra / Pa) > (Rg / Pg)? "A\n" : "G\n");
}