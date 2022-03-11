#include <iostream>

using namespace std;

int main(){

    int T1, T2, T3;

    cin >> T1 >> T2 >> T3;

    if(T1 < T2 and T1 < T3){
        cout << 1 << endl;
        if(T2 < T3) cout << 2 << endl << 3;
        else  cout << 3 << endl << 2;
    }

    else if(T1 < T2 or T1 < T3){
        if(T2 < T3) cout << 2 << endl << 1 << endl << 3;
        else cout << 3 << endl << 1 << endl << 2;
    }
    else {
        if(T2 < T3) cout << 2 << endl << 3 << endl << 1;
        else cout << 3 << endl << 2 << endl << 1;
    }

}
