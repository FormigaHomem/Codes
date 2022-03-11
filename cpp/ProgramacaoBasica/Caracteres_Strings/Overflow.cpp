#include <bits/stdc++.h>
using namespace std;
int main(){

    char op;
    int X, A, B;

    cin >> X;
    cin >> A >> op >> B;

    switch(op){
        case '*':
            if(A * B <= X){
                cout << "OK";
            }
            else{
                cout << "OVERFLOW";
            }
            break;
        default:
            if(A + B <= X){
                cout << "OK";
            }
            else{
                cout << "OVERFLOW";
            }
            break;
    }

}
