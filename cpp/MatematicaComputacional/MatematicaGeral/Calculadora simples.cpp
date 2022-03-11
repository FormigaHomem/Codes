#include <bits/stdc++.h>
using namespace std;
int main(){

    char op;
    double n1, n2, res;

    cin >> op;
    cin >> n1;
    cin >> n2;

    switch(op){
        case '+':
            res = n1 + n2;
            break;
        case '-':
            res = n1 - n2;
            break;
        case '*':
            res = n1 * n2;
            break;
        case '/':
            res = n1 / n2;
            break;
    }

    cout.precision(2);
    cout << fixed << res;

}
