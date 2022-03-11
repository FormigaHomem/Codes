#include <iostream>

#define M 1000000

using namespace std;

int main(){
    int N, A, acessos = 0, dias = 0;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> A;
        acessos += A;

        if(acessos <= M or acessos - A < M) dias++;
    }

    cout << dias;

}
