#include <iostream>

using namespace std;

int main(){

    int N, D = 0, X = 0, v[] = {0, 1, 2, 3, 4, 0, 1}, a, b;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> a >> b;
        if(v[a + 1] == b or v[a + 2] == b) D++;
        else X++;
    }

    cout << (D > X? "dario" : "xerxes");

}
