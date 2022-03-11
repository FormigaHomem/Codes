#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e4 + 10

using namespace std;

int moedas[] = {0, 100, 50, 25, 10, 5, 1}, usos[] = {0, 0, 0, 0, 0, 0, 0}, valor, ind, total;

int main(){_

    cin >> valor;

    while(ind++, valor){
        while(valor >= moedas[ind]){
            valor -= moedas[ind]; usos[ind]++; total++;
        }
    }

    cout << total << endl;
    for(int i = 1; i <= 6; i++) cout << usos[i] << endl;
}