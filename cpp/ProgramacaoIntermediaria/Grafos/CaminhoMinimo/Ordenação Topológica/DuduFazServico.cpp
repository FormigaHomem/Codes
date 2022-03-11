#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e4 + 10

using namespace std;

int T, N, M;

int main(){

    cin >> T;

    while(T--){

        cin >> N >> M;

        int grau[N + 10] = {};
        vector<int> download_before[N + 10], lista;

        for(int i = 1; i <= M; i++){
            int u, v;

            cin >> u >> v;

            download_before[v].push_back(u);
            grau[u]++;
        }

        for(int i = 1; i <= N; i++) 
            if(!grau[i]) lista.push_back(i);

        int ini = 0;
        while(ini < lista.size() ){
            int v = lista[ini++];

            for(int u : download_before[v]){
                grau[u]--;
                if(!grau[u]) lista.push_back(u);
            }
        }

        if(lista.size() < N) cout << "SIM\n";
        else cout << "NAO\n";
    }
}