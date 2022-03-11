#include <iostream>

#define MAXN (int) 1e7 + (int) 2e6 + 10

using namespace std;

typedef long long int ll;

bool eh_composto[MAXN];

ll crivo(ll x){
    eh_composto[1] = 0;
    ll primos = 0, n_esimo_primo, i = 1;
    while(++i, primos < x)
        if(!eh_composto[i]){
            n_esimo_primo = i;
            primos++;
            for(ll j = 2; j * i <= MAXN; j++) eh_composto[i * j] = true;
        }
    return n_esimo_primo;
}

int main(){

    ll N;

    cin >> N;

    cout << crivo(N);
}
