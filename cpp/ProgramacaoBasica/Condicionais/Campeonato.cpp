#include <bits/stdc++.h>
using namespace std;
int main(){

    int Cv, Ce, Cs, Fv, Fe, Fs, Cp, Fp;

    cin >> Cv >> Ce >> Cs >> Fv >> Fe >> Fs;

    Cp = (Cv * 3) + Ce;

    Fp = (Fv * 3) + Fe;

    if( (Cp > Fp) || (Cp == Fp && Cs > Fs) ){
        cout << "C";
    }
    else if( (Fp > Cp) || (Cp == Fp && Fs > Cs) ){
        cout << "F";
    }
    else if( Fp == Cp && Fs == Cs){
        cout << "=";
    }

}
