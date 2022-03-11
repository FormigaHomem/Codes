#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (long) 1e4 * 5 + 10

using namespace std;

long N, seq[MAXN], maior = 1;

int main(){

    cin >> N;

    for(int i = 1; i <= N; i++) cin >> seq[i];

    vector<long> lis(N + 1, 1), lds(N + 1, 1);
    lis[0] = 0;

    for(int i = 1; i <= N; i++){
        if(seq[i] >= lis[i - 1] + 1) lis[i] = lis[i - 1] + 1;
        else lis[i] = seq[i];
    }

    for(int i = 2; i <= N; i++)
        if(lis[i] > maior){
            bool can = true, looped = false;
            lds[i] = lis[i];
            for(int j = i + 1; j <= i + lis[i] - 1; j++){
                looped = true;
                if(seq[j] >= lds[j - 1] - 1)lds[j] = lds[j - 1] - 1;
                else{
                    can = false;
                    break;
                }
            }
            if(can and looped) maior = lis[i];
        }

    /*for(int i = 1; i <= N; i++) cout << lis[i] << " ";
    cout << endl;*/

    cout << maior << endl;
}



