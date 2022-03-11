#include <iostream>

using namespace std;

int main(){

    int N, increase = 0;
    string seq;
    char a;

    cin >> N;
    int dias[N + 10];
    dias[0] = 0;

    for(int i = 1; i < N; i++){
        cin >> a;
        if(a == 'A') dias[i] = dias[i - 1] + 1;
        else dias[i] = dias[i - 1] - 1;
        if(dias[i] + increase < 0) increase++;
    }

    for(int i = 0; i < N; i++) cout << dias[i] + increase << " ";
}
