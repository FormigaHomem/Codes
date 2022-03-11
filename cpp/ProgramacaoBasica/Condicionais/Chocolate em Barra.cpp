#include <iostream>

using namespace std;

int main(){

    int N, metade;
    pair<int, int> F1, F2;

    cin >> N >> F1.first >> F1.second >> F2.first >> F2.second;

    metade = N / 2;

    cout << ( ( (F1.first <= metade and F2.first > metade) or (F2.first <= metade and F1.first > metade) ) or ( (F1.second <= metade and F2.second > metade) or (F2.second <= metade and F1.second > metade) )? 'S' : 'N');

}
