#include <iostream>

using namespace std;

int main(){

    pair<int, int> F, S;

    cin >> F.first >> F.second >> S.first >> S.second;

    cout << (F.first * F.second > S.first * S.second? "Primeiro" : (F.first * F.second < S.first * S.second? "Segundo" : "Empate") );

}
