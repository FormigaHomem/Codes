#include <iostream>
#include <vector>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (long int)10e5+10

using namespace std;

int N, a, b;
vector<int> mobile[MAXN];
bool balanceado = true;

int dfs(int v){
    int p = 0, peso = 1, aux;
    for(int i : mobile[v]){
        aux = dfs(i);
        peso += aux;
        if(!p) p = aux;
        if(aux != p) balanceado = false;
    }
    return peso;
}

int main(){_

    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> a >> b;
        mobile[b].push_back(a);
    }

    dfs(0);

    if(balanceado) cout << "bem";
    else cout << "mal";
}
