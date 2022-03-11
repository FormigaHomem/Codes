#include <iostream>

using namespace std;

int pai[100010], peso[100010];

int Find(int x){
    if(pai[x] == x) return x;
    return pai[x] = Find(pai[x]);
}

void join(int a, int b){
    a = Find(a);
    b = Find(b);

    if(a == b) return;

    if(peso[a] > peso[b]) pai[b] = a;

    else if(peso[b] > peso[a]) pai[a] = b;

    else{
        pai[b] = a;
        peso[a]++;
    }
}

int main(){

    int N, K, b1, b2;
    char op;

    cin >> N >> K;

    for(int i = 1; i <= N; i++) {
        peso[i] = 1;
        pai[i] = i;
    }

    for(int i = 1; i <= K; i++){
        cin >> op >> b1 >> b2;
        if(op == 'F') join(b1, b2);
        else{
            if(Find(b1) == Find(b2) ) cout << 'S' << endl;
            else cout << 'N' << endl;
        }
    }

}
