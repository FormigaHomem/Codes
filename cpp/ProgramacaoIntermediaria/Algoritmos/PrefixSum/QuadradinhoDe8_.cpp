#include <bits/stdc++.h>

#define MAXN (long) 2e5 + 10
using namespace std;

long long N, num, mod[MAXN], possibilities, soma;

int main(){
    
    cin >> N;

    mod[0] = 1;
    for(int i = 1; i <= N; i++){
        cin >> num;
        soma += num;
        soma = (soma % N + N) % N;
        possibilities += mod[soma];
        mod[soma]++;
    }

    cout << possibilities << endl;
}