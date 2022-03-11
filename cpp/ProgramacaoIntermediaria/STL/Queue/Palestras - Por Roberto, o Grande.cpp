#include <iostream>
#include <queue>

using namespace std;

int main(){

    int N, pessoa, Pa;
    queue<int> entrada, filaPar, filaImpar;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> pessoa;
        if(pessoa % 2) filaImpar.push(pessoa);
        else filaPar.push(pessoa);
    }

    cin >> Pa;

    if(Pa == 1){
        while(!filaImpar.empty()) {
            cout << filaImpar.front() << " ";
            filaImpar.pop();
        }
        cout << endl;
        while(!filaPar.empty()) {
            cout << filaPar.front() << " ";
            filaPar.pop();
        }
    }
    else{
        while(!filaPar.empty()) {
            cout << filaPar.front() << " ";
            filaPar.pop();
        }
        cout << endl;
        while(!filaImpar.empty()) {
            cout << filaImpar.front() << " ";
            filaImpar.pop();
        }
    }

}
