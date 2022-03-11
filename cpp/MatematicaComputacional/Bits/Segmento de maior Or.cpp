#include <iostream>

using namespace std;

int main(){

    long long N, A = 0, a;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> a;
        A |= a;
    }

    cout << A << endl;
}
