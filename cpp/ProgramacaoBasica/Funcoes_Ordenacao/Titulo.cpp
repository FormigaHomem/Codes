#include <bits/stdc++.h>
using namespace std;

string title(string f){
    string F;
    F = f;
    F[0] = toupper(F[0]);
    for(int i = 1; i <= f.size(); i++){
        if(f[i - 1] == ' '){
            F[i] = toupper(F[i]);
        }
        else{
            F[i] = tolower(F[i]);
        }
    }
    return F;

}
int main(){

    string f;
    getline(cin, f);

    cout << title(f) << '\n';

}
