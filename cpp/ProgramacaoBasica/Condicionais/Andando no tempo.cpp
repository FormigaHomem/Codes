#include <iostream>

using namespace std;

int main(){

    int A, B, C;

    cin >> A >> B >> C;

    cout << (A == B or A == C or B == C or A + B == C or A + C == B or B + C == A? 'S' : 'N');

}
