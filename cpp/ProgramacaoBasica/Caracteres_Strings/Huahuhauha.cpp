#include <bits/stdc++.h>
using namespace std;
int main(){

    string R, V;
    int n = 0;
    getline(cin, R);
    for(int i = R.size() - 1; i >= 0; i--){
        if(R[i] != 'a' && R[i] != 'e' && R[i] != 'i' && R[i] != 'o' && R[i] != 'u'){
            R.erase(i, 1);
        }
    }
    V = R;
    reverse(V.begin(), V.end());
    (R == V)? cout << 'S': cout << 'N';
}
