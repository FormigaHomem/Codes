#include <iostream>

using namespace std;

int main(){
    int N, d = 0;

    cin >> N;

    pair<int, int> v[N + 10];

    for(int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
        d += v[i].first * v[i].second;
    }

    cout << d;

}
