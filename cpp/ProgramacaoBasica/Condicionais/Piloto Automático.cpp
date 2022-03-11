#include <bits/stdc++.h>
using namespace std;
int main(){

    int A, B, C;

    cin >> A >> B >> C;

    if( (B - A) < (C - B) ){
        cout << 1;
    }
    else if( (B - A) > (C - B) ){
        cout << -1;
    }
    else if( (B - A) == (C - B) ){
        cout << 0;
    }

}
