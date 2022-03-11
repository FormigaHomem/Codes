#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, A;
    A = 0;
    N >= 1 && N <= 80;
    
    cin >> N;
    
    char GA[N] = {'A', 'B', 'C', 'D', 'E'};
    char GP[N] = {'A', 'B', 'C', 'D', 'E'};
    
    cin >> GP;
    cin >> GA;
    
    for(int contador = 0; contador < N; contador++){
        if( (GP[contador] == 'A' && GA[contador] == 'A') || (GP[contador] == 'B' && GA[contador] == 'B') || (GP[contador] == 'C' && GA[contador] == 'C') || (GP[contador] == 'D' && GA[contador] == 'D') || (GP[contador] == 'E' && GA[contador] == 'E') ){
            A++;
        }
    }
    cout << A;
}