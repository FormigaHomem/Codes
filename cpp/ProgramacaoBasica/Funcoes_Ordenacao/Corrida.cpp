#include <iostream>
#include <algorithm>

using namespace std;

struct corredor{
    int id, tempo[110], total;
};

bool func(corredor a, corredor b){
    return a.total < b.total;
}

int main(){
    int N, M, vencedor;

    cin >> N >> M;

    corredor v[N + 10];

    for(int i = 0; i < N; i++){
        v[i].id = i + 1;
        for(int j = 0; j < M; j++){
            cin >> v[i].tempo[j];
            v[i].total += v[i].tempo[j];
        }
    }
    sort(v, v + N, func);

    cout << v[0].id;

}




