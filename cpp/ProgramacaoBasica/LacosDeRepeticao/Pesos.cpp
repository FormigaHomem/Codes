#include <iostream>

using namespace std;

int main(){

    int N;
    char R = 'S';

    cin >> N;

    int P[N + 5];

    for(int i = 0; i < N; i++){
        cin >> P[i];
        if(i > 0){
            if(P[i] - P[i - 1] > 8){
                R = 'N';
            }
        }
    }
    if(P[0] > 8){
        R = 'N';
    }

    cout << R;

}
