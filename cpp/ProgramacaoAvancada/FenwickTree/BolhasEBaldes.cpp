#include <bits/stdc++.h>

#define MAXN (int) 1e5 + 10
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define lsb(x) x & (-x) 

using namespace std;

long N, seq[MAXN], fwt[MAXN];

void update(int x){

    while(x <= N){
        fwt[x]++;
        x += lsb(x);
    }
}

int soma(int x){
    int s = 0;

    while(x > 0){
        s += fwt[x];
        x -= lsb(x);
    }

    return s;
}

void convert(){

    int temp[MAXN];
    for (int i = 1; i <= N; i++) temp[i] = seq[i];
    sort(temp + 1, temp + N + 1);

    for(int i = 1; i <= N; i++) 
        seq[i] = lower_bound(temp + 1, temp + N + 1, seq[i]) - temp;
}

long count_inversions(){
    long inversions = 0;

    convert();

    for(int i = N; i >= 1; i--){
        inversions += soma(seq[i] - 1);
        update(seq[i]);
    }

    for(int i = 1; i <= N; i++) fwt[i] = 0;

    return inversions;
}

int main(){_

    while(cin >> N, N){

        for(int i = 1; i <= N; i++) cin >> seq[i];
        
        cout << ( (count_inversions() & 1)? "Marcelo\n" : "Carlos\n" );
    }

}