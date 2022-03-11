#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    float N1, N2, N3, N4, N5, NF;

    cin >> N1 >> N2 >> N3 >> N4 >> N5;

    NF = N1 + N2 + N3 + N4 + N5 - max( {N1, N2, N3, N4, N5} ) - min( {N1, N2, N3, N4, N5} );

    cout.precision(1);
    cout << fixed << NF;

}
