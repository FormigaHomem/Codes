#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 101010
#define INF 0x3f3f3f3f
#define LOG 20
#define f first
#define s second
#define lsb(x) x & (-x)
#define endl "\n"

using namespace std;

int N, num;
string Num;
vector<int> divs;

int myPow(int base, int exp){
    if(!exp) return 1;
    int ret = base;
    while(--exp) ret *= base;
    return ret;
}

int main(){
    fastio

    cin >> Num >> N;

    for(int i = 0; i < Num.size(); i++) 
        if((int) Num[i] != 0) num += myPow(2, Num.size() - 1 - i);
    
    for(int i = 1; i <= N; i++){
        int x;
        cin >> x;
        if(num % x == 0) divs.push_back(x);
    }
    
    sort(divs.begin(), divs.end() );

    if(divs.empty() ) cout << "Nenhum\n";
    else 
        for(auto i : divs) cout << i << " ";
}