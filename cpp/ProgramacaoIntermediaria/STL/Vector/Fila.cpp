#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int N, M, S, a;

    cin >> N;

    vector<int> P;

    for(int i = 0; i < N; i++) {
        cin >> a;
        P.push_back(a);
    }

    cin >> M;

    for(int i = 0; i < M; i++){
        cin >> S;
        vector<int>::iterator went_out = find(P.begin(), P.end(), S);
        P.erase(went_out);
    }
    for(int i : P) cout << i << " ";
}

