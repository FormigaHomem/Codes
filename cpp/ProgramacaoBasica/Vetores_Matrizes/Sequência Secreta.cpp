#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, Vi;
    Vi = 0;
    
    cin >> N;
    
    int V[N];
    
    for(int i = 1; i <= N; i++){
        cin >> V[i];
        if(i >= 2 && i <= N){
            if( (V[i - 1] == 1 && V[i] == 2) || (V[i - 1] == 2 && V[i] == 1) ){
                Vi++;
            }
        }
    }
    
    cout << Vi + 1;
        
}
