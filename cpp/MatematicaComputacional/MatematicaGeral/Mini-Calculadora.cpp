#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

int main(){
    int N, D, Q, P, R, menor;

    cin >> N >> D >> Q;
    menor = min(D, Q);

    for(int i = 1; i <= menor; i++){
        if(D % i == 0 && Q % i == 0){
            R = D / i;
            P = Q / i;
        }
    }

    (R <= N && P <= N)? cout << R  << " " << P : cout << "IMPOSSIVEL";
}
