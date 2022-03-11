#include <iostream>

#define MAXN (int)1e5+10
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int N, F, C[MAXN];

long int dinheiro(int c){
    long int total = 0;

    for(int i = 0; i < N; i++) total += c / C[i];

    return total;
}

int main(){_

    cin >> N >> F;

    for(int i = 0; i < N; i++) cin >> C[i];

    long int inicio = 1, fim = 100000000, meio;

    while(inicio != fim){
        meio = (inicio + fim) / 2;
        if(dinheiro(meio) >= F) fim = meio;
        else inicio = meio + 1;
    }

    cout << inicio;

}
