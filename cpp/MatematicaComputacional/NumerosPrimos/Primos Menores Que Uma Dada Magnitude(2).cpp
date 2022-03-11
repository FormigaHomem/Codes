#include <iostream>

#define MAXN (int)10e7 + 10

using namespace std;

typedef long long int ll;

bool eh_composto[MAXN];

void crivo(ll x){
    eh_composto[1] = 0;
    for(ll i = 2; i <= x; i++)
        if(!eh_composto[i])
            for(ll j = 2; j * i <= x; j++) eh_composto[i * j] = true;
    return;
}

int main(){

    ll N;

    cin >> N;

    crivo(N);

    for(int i = 2; i <= N; i++)
        if(!eh_composto[i]) cout << i << " ";
}
