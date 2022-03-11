#include <iostream>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int K, L, fase = 0;
string camp[4] = {"oitavas", "quartas", "semifinal", "final"};

string solve(int a, int b){

    a++; b++;

    a /= 2; b /= 2;

    if(a == b) return camp[fase];
    fase++;
    return solve(a, b);
}

int main(){_

    cin >> K >> L;

    cout << solve(K, L);
}
