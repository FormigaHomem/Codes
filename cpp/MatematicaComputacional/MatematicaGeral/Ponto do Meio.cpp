#include <iostream>
#include <cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main(){_

    int N;
    long long int lados;

    cin >> N;

    /*lados = 3;

    while(--N) lados = lados * 2 - 1;*/

    lados = pow(2, N);

    cout << lados * lados;

}
