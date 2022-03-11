#include <iostream>

using namespace std;

int main(){

    int A, M;

    cin >> M >> A;

    M--;

    if(M < A) {
        if( !(A % M) ) cout << A / M;
        else cout << A / M + 1;
    }
    else cout << 1;

}
