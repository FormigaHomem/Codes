#include <iostream>

using namespace std;

int main(){

    int N, P, M, p = 0, m = 0, a;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> a;
        if(a == 1) p++;
        else m++;
    }

    cin >> P >> M;

    if(P != p or M != m) cout << 'N';
    else cout << 'S';

}
