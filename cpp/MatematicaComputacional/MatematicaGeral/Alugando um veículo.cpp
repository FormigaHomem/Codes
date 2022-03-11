#include <bits/stdc++.h>
using namespace std;
int main(){

    int km, dias;
    float total, taxa, diaria;

    cin >> dias;

    cin >> km;

    taxa = (km - 100 * dias) * 12;

    diaria = 90 * dias;

    if( ((float) km / dias) <= 100){
        total = dias * 90;
    }
    else{
        total = diaria + taxa;
    }
    cout.precision(2);
    cout << fixed << total;


}
