#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e5 + 10

using namespace std;

long N, M, distN[MAXN], distM[MAXN], Dn, Dm, last_vertexN, last_vertexM, pbN, pbM;
vector<int> circulo[MAXN], quadrado[MAXN], wayN, wayM;

void dfsN(int v, int last){
    distN[v] = distN[last] + 1;

    if(distN[v] > Dn){
        Dn = distN[v];
        last_vertexN = v;
        if(pbN) wayN.push_back(v);
    }

    for(int u : circulo[v])
        if(u != last) dfsN(u, v);
}

void dfsM(int v, int last){
    distM[v] = distM[last] + 1;

    if(distM[v] > Dm){
        Dm = distM[v];
        last_vertexM = v;
        if(pbM) wayM.push_back(v);
    }

    for(int u : quadrado[v])
        if(u != last) dfsM(u, v);
}

int main(){

    cin >> N >> M;

    for(int i = 1; i < N; i++){
        int u, v;
        cin >> u >> v;
        circulo[u].push_back(v);
        circulo[v].push_back(u);
    }

    dfsN(1, 1);

    for(int i = 1; i <= N; i++) distN[i] = 0;

    pbN = 1; Dn = 0;
    dfsN(last_vertexN, last_vertexN);

    for(int i = 1; i < M; i++){
        int u, v;
        cin >> u >> v;
        quadrado[u].push_back(v);
        quadrado[v].push_back(u);
    }

    dfsM(1, 1);

    for(int i = 1; i <= M; i++) distM[i] = 0;

    pbM = 1; Dm = 0;
    dfsM(last_vertexM, last_vertexM);
    
    cout << wayN[--Dn / 2] << " " << wayM[--Dm / 2] << endl;
}