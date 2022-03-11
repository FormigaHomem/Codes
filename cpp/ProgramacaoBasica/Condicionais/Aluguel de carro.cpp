#include <bits/stdc++.h>
using namespace std;
int main(){

    float dias, km;
    double total, desconto;

    cin >> dias;
    cin >> km;

    total = ( (dias * 30) + (0.01 * km) );

    desconto = total * 0.10;

    total -= desconto;

    cout.precision(2);
    cout << fixed << total;



}
