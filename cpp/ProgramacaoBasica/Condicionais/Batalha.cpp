#include <iostream>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main(){_

    int A1, D1, A2, D2;

    cin >> A1 >> D1 >> A2 >> D2;

    if( (A1 != D2 and A2 != D1) or (A1 == D2 and A2 == D1) ) cout << -1;
    else{
        if(A1 == D2) cout << 2;
        else cout << 1;
    }
}
