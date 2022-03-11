#include <iostream>

using namespace std;

int mdc(int a, int b){
    return (b? mdc(b, a % b) : a);
}

int main(){

    int N, Mdc, i = 1;

    cin >> N;

    int numbers[N + 10];

    for(int i = 0; i < N; i++) cin >> numbers[i];

    Mdc = mdc(numbers[0], numbers[1]);

    for(int i = 2; i < N; i++) Mdc = mdc(Mdc, numbers[i]);

    cout << Mdc;
}
