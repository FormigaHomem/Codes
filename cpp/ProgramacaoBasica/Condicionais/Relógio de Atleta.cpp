#include <iostream>

using namespace std;

int main(){

    int Fr, Fa, Co;

    cin >> Fr >> Fa >> Co;

    if(Fa > 3 * Fr or Co < 95) cout << "diminuir";
    else if(Fa < 2 * Fr and Co > 97) cout << "aumentar";
    else cout << "manter";

}
