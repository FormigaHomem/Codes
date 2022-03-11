#include <iostream>
#include <set>

using namespace std;

int main(){

    int C, a, encomendas = 0;
    set<int> tacos;

    cin >> C;

    for(int i = 0; i < C; i++){
        cin >> a;
        if(tacos.find(a) == tacos.end() ) {
            encomendas += 2;
            tacos.insert(a);
        }
        else tacos.erase(a);

    }

    cout << encomendas;

}
