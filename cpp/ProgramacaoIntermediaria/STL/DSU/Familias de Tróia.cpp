#include <iostream>

using namespace std;

#define MAXN 5 * 10000 + 10

int N, M, a, b, pai[MAXN], peso[MAXN] = {0}, families = 0;

int Find(int x){
    if(pai[x] == x) return x;
    return pai[x] = Find(pai[x]);
}

void join(int a, int b){

    a = Find(a);
    b = Find(b);

    if(peso[a] > peso[b]) pai[b] = a;
    else if(peso[b] > peso[a]) pai[a] = b;
    else{
        pai[b] = a;
        peso[a]++;
    }

}

int main(){

    cin >> N >> M;

    for(int i = 0; i < N; i++) pai[i] = i;

    for(int i = 0; i < M; i++){
        cin >> a >> b;
        join(a, b);
    }

    for(int i = 0; i < N; i++)
        if(Find(i) == i) families++;

    cout << families;

}
