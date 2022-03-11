#include <bits/stdc++.h>
using namespace std;
int main(){

    int T[4], t = 0;

    for(int i = 0; i < 4; i++){
        cin >> T[i];
        if(i < 3){
            t += T[i] -1;
        }
        else{
            t += T[i];
        }
    }

    cout << t;

}
