#include <iostream>

using namespace std;

int main(){

    unsigned long long int somap = 0, somai = 0, alg;
    string a;

    cin >> a;

    for(int i = 1; i <= a.size(); i++) {
        if(i % 2 == 0) somap += (a[i - 1] - '0');
        else somai += (a[i - 1] - '0');
    }

    alg = somap - somai;

    if(alg % 11 == 0) cout << "S\n";
    else cout << "N\n";

}
