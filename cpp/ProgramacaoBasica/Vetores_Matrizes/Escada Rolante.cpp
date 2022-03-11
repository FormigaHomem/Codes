#include <iostream>

using namespace std;

int main(){
    int N, seconds = 10;

    cin >> N;

    int v[N + 10];

    for(int i = 0; i < N; i++) cin >> v[i];
    for(int i = N - 1; i > 0; i--){
        if(v[i] - v[i - 1] < 10) seconds += v[i] - v[i - 1];
        else seconds += 10;
    }

    cout << seconds;

}
