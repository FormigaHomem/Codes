#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

string s;

long lis(){
    string pilha;
    
    for(char i : s){

        auto it = upper_bound(pilha.begin(), pilha.end(), i);

        if(it == pilha.end() ) pilha += i;

        else *it = i;
    }
    
    return pilha.size();
}

int main(){_

    cin >> s;

    cout << lis() << endl;
}