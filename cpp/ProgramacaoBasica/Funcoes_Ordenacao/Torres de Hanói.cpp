#include <bits/stdc++.h>
using namespace std;
int fr(int n){
    if(n == 1){
        return 1;
    }
    return fr(n - 1) * 2 + 1;
}

int main(){
    int n[31], i = 0;

    cin >> n[i];

    while(n[i] != 0){
        i++;
        cin >> n[i];
    }
    for(int j = 0; j < i; j++){
        cout << "Teste " << j + 1 << "\n" << fr(n[j]) << endl;
    }
}
