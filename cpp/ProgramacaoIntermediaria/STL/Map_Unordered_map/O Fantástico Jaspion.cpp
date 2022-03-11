#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main(){

    int T;

    cin >> T;

    while(T--){
        int M, N;
        map<string, string> dicio;
        vector<string> letra;
        string aux1, aux2;

        cin >> M >> N;
        cin.ignore();

        for(int i = 0; i < M; i++){
            getline(cin, aux1);
            getline(cin, aux2);
            dicio[aux1] = aux2;
        }

        for(int i = 0; i < N; i++){
            getline(cin, aux1);
            letra.push_back(aux1);
        }

        for(string i : letra){
            vector<string> aux;
            string aux3;
            for(char j : i){
                aux3 += j;
                if(j == ' '){
                    aux.push_back(aux3);
                    aux3 = "";
                }
            }
            aux.push_back(aux3);
            for(string j : aux){
                if( *(j.end() - 1) == ' ') j.erase(j.end() - 1);
                if(dicio.find(j) != dicio.end() ) cout << dicio.find(j)->second << " ";
                else cout << j << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

}
