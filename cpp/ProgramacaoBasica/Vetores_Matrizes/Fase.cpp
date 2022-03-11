#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int N, k;

    cin >> N >> k;

    int comp[N + 10];

    for(int i = 0; i < N; i++) cin >> comp[i];

    sort(comp, comp + N);

    if(comp[N - k] != comp[N - 1 - k]) cout << k << endl;
    else{
        int *lower = lower_bound(comp, comp + N, comp[N - k]);
        cout << N - (lower - comp) << endl;
    }
}
