#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int N, x, precos[100010], dnh = 0;

    cin >> N;

    for(int i = 0; i < N; i++) cin >> precos[i];

    sort(precos, precos + N, [](int a, int b) {return a > b;} );

    for(int i = 0; i < N; i++)
        if( (i + 1 % 3) ) dnh += precos[i];

    cout << dnh;

}
