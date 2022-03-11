#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main(){

    int N;

    cin >> N;
    cin.ignore();

    vector<string> A;
    string Aux;
    while(N--){
        getline(cin, Aux);
        A.push_back(Aux);
    }

    stack<char> chaves;
    for(string i : A){
        for(char j : i){
            if(j == '{') chaves.push(j);
            else if(j == '}'){
                if(chaves.empty() ){
                    cout << 'N';
                    return 0;
                }
                chaves.pop();
            }
        }
    }
    if(chaves.empty() ) cout << 'S';
    else cout << 'N';

}
