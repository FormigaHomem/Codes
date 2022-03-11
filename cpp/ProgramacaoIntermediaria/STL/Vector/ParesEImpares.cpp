#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 101010
#define INF 0x3f3f3f3f
#define LOG 20
#define endl '\n'
#define lsb(x) x & (-x)
#define f first
#define s second

using namespace std;

bool isEven(int a){
    return !(a & 1);
}

int N;

int main(){
    fastio

    cin >> N;

    vector<int> seq(N);

    for(int i = 0; i < N; i++) cin >> seq[i];
    
    sort(seq.begin(), seq.end(), [] (int a, int b) {
        if(isEven(a) ){
            if(isEven(b) ) return a < b;
            return true;
        }

        else{
            if(isEven(b) ) return false;
            else return a > b;
        }
    });

    for(auto i : seq) cout << i << endl;
}