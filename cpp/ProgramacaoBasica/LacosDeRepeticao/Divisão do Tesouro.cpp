#include <iostream>

using namespace std;

int A, N;

int solve(){
    for(int i = 0; i < A; i++)
        if(i * N + i * 2 == A) return i * 2;
}

int main(){

    cin >> A >> N;

    cout << solve();

}
