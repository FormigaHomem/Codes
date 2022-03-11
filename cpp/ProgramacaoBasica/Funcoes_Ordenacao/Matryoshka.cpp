#include <bits/stdc++.h>
using namespace std;

int main(){

    int N, ordenado = 0;

    cin >> N;

    vector<int> D(N), C(N), M;

    for(int i = 0; i < N; i++){
        cin >> D[i];
        C[i] = D[i];
    }

    sort(D.begin(), D.end());

    for(int i = 0; i < N; i++){
        //cout << D[i] << " " << C[i] << endl;
        if(D[i] != C[i]){
            M.push_back(D[i]);
        }
    }


    cout << M.size() << endl;

    for(int i = 0; i < M.size(); i++){
        cout << M[i] << " ";
    }

}
