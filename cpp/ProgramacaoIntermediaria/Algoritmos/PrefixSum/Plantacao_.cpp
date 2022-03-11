#include <bits/stdc++.h>

using namespace std;

#define MAXN (long) 1e5 + 10
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

long long N, K, arvore[MAXN], soma, ans;
char tempo;

int main(){_

    cin >> N >> K;

    for(int i = 1; i <= K; i++){
        cin >> arvore[i];
        soma += arvore[i];
    }

    sort(arvore + 1, arvore + K + 1);

    int index = 1, dif = 0;
    while(N--){
        cin >> tempo;

        if(K){
            if(tempo == 'C'){
                dif--;
                ans += soma + K;
                soma += K;
            }

            else{
                dif++;
                ans += soma - K;
                soma -= K;
            }
        }
        while(arvore[index] == dif and K > 0) {
            K--;
            ++index;
        }
    }

    cout << ans;
}