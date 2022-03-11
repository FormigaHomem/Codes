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

long N, people[MAXN], ft[MAXN];
char task;

void update(int x, int k){
    while(x <= N){
        ft[x] += k;
        x += lsb(x);
    }
}

long sum(int x){
    long ret = 0;
    while(x > 0){
        ret += ft[x];
        x -= lsb(x);
    }

    return ret;
}

int main(){
    fastio
    
    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> people[i];
        update(i, people[i]);
    }

    while(cin >> task){
        int id;
        cin >> id;

        if(task == 'a') update(id, -people[id]);
        else cout << sum(id - 1) << endl;
    }
}