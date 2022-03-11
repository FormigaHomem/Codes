#include <iostream>
#include <algorithm>

using namespace std;

int ord(int a, int b){
    return a > b;
}

int main(){

    int N, M, Aux = 1, x = 0, cont = 0;

    cin >> N >> M;

    int moedas[N + 5];

    for(int i = 0; i < N; i++){
        cin >> moedas[i];
    }

    sort(moedas, moedas + N, ord);

    while(Aux){
        Aux = M;
        for(int i = x; i < N; i++){
            while(Aux >= moedas[i]){
                Aux -= moedas[i];
                cont++;
            }
            if(x == N - 1 && (Aux || cont >= 10) ){
                cout << 'N';
                return 0;
            }
            if(Aux == 0 && cont < 10){
                cout << 'S';
                return 0;
            }
        }
        x++;
        cont = 0;
    }

}
