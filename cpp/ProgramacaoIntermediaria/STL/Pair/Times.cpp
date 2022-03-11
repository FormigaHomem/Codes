#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int N, M, x = 1;

    cin >> N >> M;

    vector<vector<pair<string, int> > > aluno(M);

    pair<int, string> Aux[N + 10];

    for(int i = 0; i < N; i++) cin >> Aux[i].second >> Aux[i].first;

    sort(Aux, Aux + N);

    for(int i = N - 1; i >= 0; i -= M)
        for(int j = 0; j < M and i - j >= 0; j++) aluno[j].push_back(make_pair(Aux[i - j].second, Aux[i - j].first) );

    for(int i = 0; i < M; i++) sort(aluno[i].begin(), aluno[i].end() );

    for(vector<pair<string, int> > i : aluno){
        cout << "Time " << x++ << endl;
        for(pair<string, char> j : i) cout << j.first << endl;
        cout << endl;
    }

}
