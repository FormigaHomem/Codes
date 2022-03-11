#include <iostream>

using namespace std;

int main(){

    string N;
    int moves = 0, horario, anti_horario, pos = 10, roleta[] = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    cin >> N;

    for(int i = 0; i < (int)N.size(); i++){
        int integer = N[i] - '0', posanti, poshora;
        horario = 0; anti_horario = 0;
        int j;
        for(j = pos; roleta[j] != integer; j++){
            if(!roleta[j]) j = 10;
            horario++;
        }
        poshora = j;
        for(j = pos; roleta[j] != integer; j--){
            if(!roleta[j]) j = 10;
            anti_horario++;
        }
        posanti = j;
        pos = (horario <= anti_horario? poshora : posanti);
        moves += min(horario, anti_horario);
    }

    cout << moves << endl;
}
