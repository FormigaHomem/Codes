#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e3 + 10

using namespace std;

int N;

int main(){

    while(cin >> N){

        int grau[MAXN] = {}, minutes = 0, camada[MAXN] = {}, level[MAXN] = {};
        vector<int> download_before[MAXN] = {}, lista = {};

        for(int u = 1; u <= N; u++){
            camada[u - 1] = 0;
            int i, v;
            cin >> i;
            grau[u] = i;
            if(!i){
                lista.push_back(u);
                if(!camada[0]){
                    minutes++; 
                    camada[0] = 1; level[u] = 0;
                }
            }
            while(i--){
                cin >> v;
                download_before[v].push_back(u);
            }
        }

        int ini = 0;
        while(ini < lista.size() ){
            int v = lista[ini++];

            for(int u : download_before[v]){
                grau[u]--;
                if(!grau[u]){
                    lista.push_back(u);
                    level[u] = level[v] + 1;
                    if(!camada[level[u] ]){
                        minutes++;
                        camada[level[u] ] = 1;
                    }
                }
            }
        }

        if(lista.size() < N) cout << -1 << endl;
        else cout << minutes << endl;
    }
}