#include <iostream>

using namespace std;

int main(){

    int N;

    cin >> N;

    int seq[N + 5];

    for(int i = 0; i < N; i++){
        cin >> seq[i];
    }

    for(int i = 1; i < N - 1; i++){
        if(seq[i] < seq[i - 1] && seq[i] < seq[i + 1]){
            cout << 'S';
            return 0;
        }
    }

    cout << 'N';

}
