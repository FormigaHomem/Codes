#include <iostream>

using namespace std;

typedef long long int ll;

bool eh_primo(ll x){
    for(ll i = 2; i * i <= x; i++)
        if(x % i == 0) return false;
    return true;
}

int main(){

    ll N;

    cin >> N;

    cout << (eh_primo(N)? 'N' : 'S') << endl;

}
