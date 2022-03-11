#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int A, B, C, op1, op2, op3;

    cin >> A >> B >> C;

    op1 = (2 * B) + (4 * C);
    op2 = (2 * A) + (2 * C);
    op3 = (4 * A) + (2 * B);

    cout << min(op1, min(op2, op3) );

}
