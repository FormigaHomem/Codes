#include <iostream>

using namespace std;

int main(){

    int V, T;

    cin >> V >> T;

    while(T--){
        int a;
        cin >> a;
        V += a;
        if(V > 100) V = 100;
        if(V < 0) V = 0;
    }
    cout << V;
}
