#include <iostream>

using namespace std;

int main(){

    int a, b;

    cin >> b >> a;

    if(a > 0){
        if (b > 0) cout << "Q1";
        else if(b < 0) cout << "Q2";
        else cout << "eixos";
    }
    else if (a < 0){
        if (b > 0) cout << "Q4";
        else if(b < 0) cout << "Q3";
        else cout << "eixos";
    }
    else cout << "eixos";

}
