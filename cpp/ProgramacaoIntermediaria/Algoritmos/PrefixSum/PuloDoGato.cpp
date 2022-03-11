#include <iostream>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e4 + 10

using namespace std;

long N, lajota[MAXN], psa[MAXN];
bool stop;

int main(){_

    

    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> lajota[i];
        if(i == 1) psa[i] = 1;
        else if(lajota[i] and !stop){
            psa[i] = (lajota[i - 2]? psa[i - 2] + 1 : (lajota[i - 1]? psa[i - 1] + 1 : -1) );
            if(psa[i] == -1){
                psa[N] = 0;
                stop = true;
            }
        }
    }

    cout << psa[N] - 1 << endl;
}