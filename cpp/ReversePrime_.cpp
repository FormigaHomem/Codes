#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout.tie(NULL);
#define MAXN (l) 1e8
#define INF 0x3f3f3f3f
#define LOG 30
#define f first
#define s second
#define lsb(x) x & (-x)
#define endl "\n"

using namespace std;

typedef long l;

l isCompound[MAXN], ft[MAXN], pos[MAXN];
vector<l> reversePrimes, primes;

l primeFactors(l x){
    l ans = 0, i = 0;
    while(x > 1){
        while( !(x % primes[i]) ) x %= primes[i], ans++;
        i++;
    }
    if(x <= 1000240) cout << ans << endl;
    return ans;
}

void makePrimes(){
    isCompound[1] = 1;
    for(int i = 2; i < MAXN; i++){
        string S = to_string(i), reverse;
        if(S.size() == 7 and S[6] == '0'){
            reverse_copy(S.begin(), S.end() - 1, reverse.begin() );
            if(!isCompound[stol(reverse)]){
                pos[i] = reversePrimes.size() - 1;
                reversePrimes.push_back(i);
            }
        }

        if(!isCompound[i]){
            primes.push_back(i);
            for(int j = 2; i * j < MAXN; j++) isCompound[i * j] = 1;
        }
    }
}

void update(int x, l k){
    for(;x < MAXN; x += lsb(x) ) ft[x] += k;
}

l sum(int x){
    long ret = 0;
    for(;x > 0; x -= lsb(x) ) ret += ft[x];
    return ret;
}

int main(){
    //fastio

    char task;
    long x;

    makePrimes();
    for(l i = 0; i < reversePrimes.size(); i++){
        if(i <= 3) cout << reversePrimes[i] << " ";
        update(i + 1, primeFactors(reversePrimes[i] ) );
    }   cout << endl;
    
    while(cin >> task >> x){
        if(task == 'q') cout << sum(--x) << endl;
        else update(pos[x], -1);
    }
}