#include <iostream>
#include <utility>

using namespace std;

int main(){

    pair<int, pair<int, int> > cartas;

    cin >> cartas.first >> cartas.second.first >> cartas.second.second;

    if(cartas.first == cartas.second.first){
        cout << cartas.second.second;
    }else{
        if(cartas.first == cartas.second.second){
            cout << cartas.second.first;
        }
        else{
            cout << cartas.first;
        }
    }

}
