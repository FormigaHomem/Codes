#include <iostream>

using namespace std;

int main(){

    int N, X, Y, Z, menor1, menor2, maior;

    cin >> N >> X >> Y >> Z;

    if(X <= N or Y <= N or Z <= N){
        if(X + Y <= N or X + Z <= N or Y + Z <= N){
            if(X + Y + Z <= N) cout << 3;
            else cout << 2;
        }
        else cout << true;
    }
    else cout << false;

}
