#include <iostream>

using namespace std;

int main(){

    int A, B, C;

    cin >> A >> B >> C;

    A /= 2;
    B /= 3;
    C /= 5;

    cout << min(A, min(B, C) );
}
