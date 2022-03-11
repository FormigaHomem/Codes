#include <bits/stdc++.h>
using namespace std;
int main(){

    char op;
    double A, B;

    cin >> op;
    cin >> A >> B;

    cout.precision(2);
    if(op == 'M'){
        cout << fixed << A * B;
    }
    else{
        cout << fixed << A / B;
    }

}
