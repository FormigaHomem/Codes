#include <iostream>

using namespace std;

int main(){

    int G, P, S, C[G][P], K[101][101];

    do{
        cin >> G >> P;
        if(G == 0 and P == 0) break;
        for(int i = 0; i < G; i++){
            for(int j = 0; j < P; j++){
                cin >> C[i][j];
            }
        }
        cin >> S;
        for(int i = 0; i < S; i++){
            cin >> K[i][0];
            for(int j = 1; j <= K[i][0]; j++){
                cin >> K[i][j];
            }
        }
        /*cout << G << " " << P << endl;
        for(int i = 0; i < G; i++){
            for(int j = 0; j < P; j++){
                cout << C[i][j] << " ";
            }
            cout << endl;
        }
        cout << S << endl;
        for(int i = 0; i < S; i++){
            cout << K[i][0] << " ";
            for(int j = 1; j <= K[i][0]; j++){
                cout << K[i][j] << " ";
            }
            cout << endl;
        }*/
    }while(G != 0 && P != 0);

}
