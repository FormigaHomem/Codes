#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int x, y, x2, y2, N, insensibilidade = 0;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> x >> y >> x2 >> y2;
        insensibilidade += (pow(abs(x2 - x), 2) + pow(abs(y2 - y), 2) );
    }

    cout << insensibilidade;
}
