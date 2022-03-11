#include <iostream>

using namespace std;

int main(){

    int K;

    cin >> K;

    if( !(K % 8) ) cout << 3;
    else if( !( (K % 8) % 6) or K == 6) cout << 1;
    else if( !( (K % 8) % 7) or K == 7) cout << 2;

}
