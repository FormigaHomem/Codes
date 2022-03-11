#include <iostream>

using namespace std;

int main(){

    int a, resp = 0;

    for(int i = 0; i < 3; i++){
        cin >> a;
        if( !(a % 2) or !(a % 5) ) resp++;
    }

    cout << resp;

}
