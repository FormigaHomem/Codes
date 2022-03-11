#include <iostream>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e8

using namespace std;

int main(){_

    unsigned long long X;

    cin >> X;

    if(X % 49 == 0) cout << X / 49 * 2;
    else if(X % 49 < 5) cout << (X / 49) * 2 + 1;
    else cout << (X / 49) * 2 + 2;
}
