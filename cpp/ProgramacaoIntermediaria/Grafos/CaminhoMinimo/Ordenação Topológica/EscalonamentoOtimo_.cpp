#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 6e4

using namespace std;

long long int N, M, a, b, grau[MAXN], aux;
vector<int> grafo[MAXN], lista;

int main(){_
    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        grau[b]++;
        grafo[a].push_back(b);
    }

    for(int i = 0; i < N; i++)
       if(!grau[i]) lista.push_back(i);

    int ini = 0;
    while(ini < lista.size() ){

        int atual = lista[ini++];

        for(int i : grafo[atual]){
            grau[i]--;
            if(!grau[i]) {
                for(int j = ini; j <= lista.size(); j++) 
                    if(i < lista[j] or j == lista.size() ){
                        lista.insert(lista.begin() + j, i);
                        break;
                    }
            }
        }
    }

    if(lista.size() < N) cout << "*\n";
    else
        for(int i : lista) cout << i << endl;
}