#include <iostream>

using namespace std;

long int arvores[1010] = {-1}, soma = 0, ans = 0, x;
char tempo;


int main(){

    long int N, K;

    cin >> N >> K;

    for(int i = 0; i < K; i++){
        cin >> x;
        arvores[x] += 1;
        soma += x;
    }

    for(int i = 0; i < N; i++){
        cin >> tempo;
        if(K){
            if(tempo == 'C'){
                for(int j = 1; j <= 1000; j++){
                    if(arvores[j] != -1) {
                        arvores[j + 1] = arvores[j];
                        arvores[j] = -1;
                    }
                }

                ans += soma + K;
                soma += K;
                cout << ans << " " << soma << " " << K << endl;
            }

            else{
                cout << ans << " " << soma << " " << K << endl;
                ans += soma - K;
                soma -= K;
                for(int j = 1; j <= 1000; j++){
                    if(arvores[j] != -1){
                        arvores[j - 1] = arvores[j];
                        arvores[j] = -1;
                    }
                }
                if(arvores[0] != -1){
                    K -= arvores[0];
                    arvores[0] = -1;
                }
                cout << ans << " " << soma << " " << K << endl;
            }
        }
    }

    cout << ans;

}
