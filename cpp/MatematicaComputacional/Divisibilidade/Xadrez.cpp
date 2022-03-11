#include <iostream>

using namespace std;

int main(){

    int L, C;

    cin >> L >> C;

    int cor = (C % 2);

    if (L % 2) cout << cor;
    else cout << !cor;

}
