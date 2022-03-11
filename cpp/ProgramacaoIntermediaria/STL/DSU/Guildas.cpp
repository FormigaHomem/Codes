#include <iostream>

#define MAXN 100010

using namespace std;

int pai[MAXN], peso[MAXN];

int Find(int x){
    if(pai[x] == x) return x;
    return pai[x] = Find(pai[x]);
}

void join(int a, int b){
    //cout << a << " " << b << " ";
    a = Find(a);
    b = Find(b);
    //cout << a << " " << b << " " << peso[a] << " " << peso[b] << endl;

    if(a == b) return;

    if(peso[a] > peso[b]) {
        pai[b] = a;
        peso[a]+= peso[b];
    }

    else if(peso[b] > peso[a]) {
        pai[a] = b;
        peso[b]+= peso[a];
    }

    else{
        pai[b] = a;
        peso[a]+= peso[b];
    }
    //cout << a << " " << b << " " << peso[a] << " " << peso[b] << endl;
}

int main(){

    int N, M, Q, A, B;
    while(cin >> N >> M, M){
        int win = 0;

        for(int i = 1; i <= N; i++) {
            cin >> peso[i];
            pai[i] = i;
        }

        for(int i = 1; i <= M; i++){
            cin >> Q >> A >> B;
            if(Q == 1) join(A, B);
            else{
                if(peso[Find(A)] != peso[Find(B)] )
                    if( (peso[pai[A] ] > peso[pai[B] ] and pai[A] == pai[1] ) or (peso[pai[A] ] < peso[pai[B] ] and pai[B] == pai[1] ) ) win++;
            }
        }

        cout << win << endl;
    }

}
