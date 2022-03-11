#include <iostream>

using namespace std;

int main(){

    int A, B, C;

    cin >> A >> B >> C;

    if(A == B and B == C) cout << '*';
    else cout << (A == B? 'C' : (A == C? 'B' : 'A') );

}
