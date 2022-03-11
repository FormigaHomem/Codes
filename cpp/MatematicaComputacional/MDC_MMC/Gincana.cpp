#include <iostream>

using namespace std;

int mdc(long int a, long int b){

    long int r;

    while(b != 0){
        //cout << a << " " << b << " " << a % b << endl;
        r = a % b;
        a = b;
        b = r;
    }
    //cout << a << " " << b << endl << endl << endl;
    return a;
}

int main(){

    long int N, M, x;

    cin >> N >> M;

    x = M;

    while(mdc(N, x) > 1) x--;

    cout << x;
}
