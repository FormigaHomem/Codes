#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e5 + 10
#define lsb(x) x & (-x)

using namespace std;

long ft1[MAXN], ft2[MAXN], N, seq1[MAXN], seq2[MAXN], res1[MAXN], res2[MAXN];
set<long> temp;

long query1(int x){
    long s = 0;

    while(x > 0){
        s = max(s, ft1[x]); 
        x -= lsb(x);
    }

    return s;
}

long query2(int x){
    long s = 0;

    while(x <= N){
        s = max(s, ft2[x]); 
        x += lsb(x);
    }

    return s;
}

void update1(int x){

    long max_lis = query1(x - 1) + 1;

    while(x <= N){
        ft1[x] = max(ft1[x], max_lis);
        x += lsb(x);
    }
}

void update2(int x){

    long max_dec_lis = query2(x + 1) + 1;

    while(x > 0){
        ft2[x] = max(ft2[x], max_dec_lis);
        x -= lsb(x);
    }
}

void convert(){
    map<long, int> mp; int ind = 1;
    for(auto it : temp)
        mp[it] = ind++;

    for(int i = 1; i <= N; i++){
        seq1[i] = mp[seq1[i] ];
        seq2[i] = temp.size() - seq1[i] + 1;
    }
}

int tam(){

    long ans = 0;

    convert();

    for(int i = 1; i <= N; i++){
        update1(seq1[i]);
        res1[i] = ft1[seq1[i] ];
    }

    for(int i = N; i >= 1; i--){
        update2(seq2[i]);
        res2[i] = ft2[seq2[i] ];
    }

    for(int i = 1; i <= N; i++)
        if(res1[i] == res2[i] ) ans = max(ans, res1[i] );

    /*cout << "\nseq:\n";
    for(int i = 1; i <= N; i++) cout << seq1[i] << " ";
    cout << "\nseq2:\n";
    for(int i = 1; i <= N; i++) cout << seq2[i] << " ";
    cout << "\n\nres1:\n";
    for(int i = 1; i <= N; i++) cout << res1[i] << " ";
    cout << "\nres2:\n";
    for(int i = 1; i <= N; i++) cout << res2[i] << " ";
    cout << endl;*/
    return ans - 1;
}

int main(){_

    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> seq1[i]; 
        temp.insert(seq1[i]);
    }

    cout << 2 * tam() + 1 << endl;
}