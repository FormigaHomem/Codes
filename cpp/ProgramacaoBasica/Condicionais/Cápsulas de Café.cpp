#include <bits/stdc++.h>
using namespace std;
int main(){

    int n, doadas, xicaras;
    char tam;

    doadas = 0;

    for(int i = 0; i < 7; i++){
        cin >> n;
        cin >> tam;

        if( (tam == 'P') || (tam == 'p')){
            doadas += (n * 10);
        }
        else if( (tam == 'G') || (tam == 'g')){
            doadas += (n * 16);
        }
    }
    xicaras = (doadas * 2) / 7;

    cout << doadas << endl;
    cout << xicaras << endl;

}
