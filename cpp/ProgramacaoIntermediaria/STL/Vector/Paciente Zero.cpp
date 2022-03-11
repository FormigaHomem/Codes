#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int N, M, P, id, infectados, x = 1;

    cin >> N >> M;

    vector<int> pacientes[N + 10], paciente_zero;

    for(int i = 0; i < M; i++){
        cin >> id >> P;
        for(int j = 0; j < P; j++){
            cin >> infectados;
            pacientes[infectados].push_back(id);
        }
    }

    for(int i = 1; i <= N; i++){
        if(pacientes[i].empty() ) paciente_zero.push_back(x);
        x++;
    }

    sort(paciente_zero.begin(), paciente_zero.end() );
    for(int i : paciente_zero) cout << i << endl;

}
