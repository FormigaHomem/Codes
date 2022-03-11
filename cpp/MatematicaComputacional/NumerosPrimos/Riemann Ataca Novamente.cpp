#include <iostream>

#define MAXN (int)1e5 * 13 + 10

using namespace std;

typedef long long int ll;

bool eh_composto[MAXN];
ll primos[MAXN];

void crivo(){
    eh_composto[1] = 0;
    ll pos = 1;
    for(int i = 2; i < MAXN; i++)
        if(!eh_composto[i]){
            primos[i] = pos++;
            for(ll j = 2; j * i <= MAXN; j++) eh_composto[i * j] = true;
        }
    return;
}

int main(){

    ll Q, p;

    cin >> Q;

    crivo();

    for(int i = 0; i < Q; i++){
        cin >> p;
        cout << primos[p] << endl;
    }
}
