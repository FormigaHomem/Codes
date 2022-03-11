#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

char oposto(char a){
    return (a == '('? ')' : (a == '['? ']' : (a == '{'? '}' : '!') ) );
}

int main(){

    int T, x;
    string A;
    bool ok;

    cin >> T;

    for(int i = 0; i < T; i++){
        cin >> A;
        stack<char> abre;
        ok = true;
        for(char j : A){
            if(oposto(j) != '!') abre.push(j);
            else{
                if(abre.empty() or j != oposto(abre.top() ) ){
                    cout << "N" << endl;
                    ok = false;
                    break;
                }
                abre.pop();
            }
        }
        if(ok) cout << "S" << endl;
    }

}
