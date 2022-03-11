#include <iostream>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN

using namespace std;

int V, P, parcela[20];

int main(){

    cin >> V >> P;

    if(V % P == 0)
        for(int i = 1; i <= P; i++) cout << V / P << endl;
    else{
        parcela[V % P] = V / P; parcela[0] = V / P + 1;
        for(int i = 0; i < P; i++){
            if(!parcela[i]) parcela[i] = parcela[i - 1];
            cout << parcela[i] << endl;
        }
    }

}
