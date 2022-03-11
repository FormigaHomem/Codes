#include <iostream>

using namespace std;

int main(){

    int N, n = 0, Moedas[6] = {100, 50, 25, 10, 5, 1}, i = 0;

    cin >> N;

    while(N != 0){
        if(N >= Moedas[i]){
            N -= Moedas[i];
            n++;
        }
        else i++;
    }

    cout << n;

}
