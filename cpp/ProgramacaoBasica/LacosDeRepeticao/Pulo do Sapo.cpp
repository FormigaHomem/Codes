#include <iostream>

using namespace std;

bool pulou[210];

int main(){

    int N, M;

    cin >> M >> N;

    pair<int, int> sapo[110];

    for(int i = 1; i <= N; i++) cin >> sapo[i].first >> sapo[i].second;

    for(int i = 1; i <= N; i++){
        int aux;
        for(int j = sapo[i].first; j <= M; j += sapo[i].second) pulou[j] = true;
        for(int j = sapo[i].first; j > 0; j -= sapo[i].second) pulou[j] = true;
    }

    for(int i = 1; i <= M; i++) cout << pulou[i] << endl;
}
