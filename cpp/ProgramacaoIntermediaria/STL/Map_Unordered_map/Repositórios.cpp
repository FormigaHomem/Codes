#include <iostream>
#include <map>

using namespace std;

int main(){

    int N, C, a, b;

    cin >> C >> N;

    map<int, int> instalados, internet;
    map<int, int> instalar;

    for(int i = 0; i < C; i++){
        cin >> a >> b;
        instalados[a] = b;
    }
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        internet[a] = b;
        if(instalar.find(a) != instalar.end()) {
            if(instalados.find(a)->second < internet[a]) instalar[a] = max(instalar[a], b);
            else instalar[a] = b;
        }
    }


    for(pair<int, int> i : instalar) {
        cout << i.first << " " << i.second << endl;
    }

}
