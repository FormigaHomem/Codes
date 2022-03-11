#include <iostream>

using namespace std;

int main(){
    int N, M;

    cin >> N >> M;

    long int A[N + 5], F[N + 5], O;

    for(int i = 0; i < N - 1; i++){
        cin >> A[i];
    }
    for(int i = 0; i < N; i++){
        cin >> F[i];
    }
    for(int i = 0; i < M; i++){
        cin >> O;
        long int inicio = 0, fim = N - 2, pos, res = -1;

        while(inicio <= fim){
            pos = (inicio + fim) / 2;
            if(A[pos] <= O){
                inicio = pos + 1;
                res = pos;
            }
            else fim = pos - 1;
            //cout << "res " << res << " " << "pos " << pos << " " << "inicio " << inicio << " " << "fim " << fim << " " << "A[pos] " << A[pos] << " " << "O " << O << endl;
        }
        cout << F[res + 1] << " ";
    }

}
