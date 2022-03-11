#include<bits/stdc++.h>

#define MAXN (int) 1e2

using namespace std;

long B, N, C, D, V, din[MAXN];

int main(){

    loop:
    while(cin >> B >> N, N){

        for(int i = 1; i <= B; i++) cin >> din[i];

        for(int i = 1; i <= N; i++){
            cin >> C >> D >> V;
            din[C] -= V;
            din[D] += V;
        }

        for(int i = 1; i <= B; i++)
            if(din[i] < 0){
                cout << "N\n";
                goto loop;
            }
        cout << "S\n";
    }
}