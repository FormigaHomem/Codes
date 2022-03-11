#include <iostream>
#include <algorithm>

using namespace std;

struct consultas{
    int inicio, fim;
};

int ord(consultas a, consultas b){
    return a.fim < b.fim;
}

int main(){

    int N, n = 1, livre = 0;

    cin >> N;

    consultas horario[N + 5];

    for(int i = 0; i < N; i++){
        cin >> horario[i].inicio >> horario[i].fim;
    }

    sort(horario, horario + N, ord);

    livre = horario[0].fim;

    for(int i = 1; i < N; i++){
        if(horario[i].inicio >= livre){
            n++;
            livre = horario[i].fim;
        }
    }

    cout << n;

}
