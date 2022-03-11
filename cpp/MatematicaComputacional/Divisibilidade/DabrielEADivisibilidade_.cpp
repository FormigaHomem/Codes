#include <bits/stdc++.h>

using namespace std;

long N, M, a;
set<long> num;
string n;
bool found;

int main(){

    cin >> n >> M;

    for(char i : n){
        int integer = i - '0';
        N = N * 2 + integer;
    }

    for(int i = 1; i <= M; i++){
        cin >> a;
        num.insert(a);
    }

    for(long i : num)
        if(N % i == 0){
            cout << i << " ";
            found = true;
        }
    
    if(!found) cout << "Nenhum";
}