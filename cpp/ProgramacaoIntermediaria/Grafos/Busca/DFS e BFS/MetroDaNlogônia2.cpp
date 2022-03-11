#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e5 + 10

using namespace std;

long N, M, visited[MAXN], furtherVertexC, furtherVertexQ, distQ[MAXN], distC[MAXN], pbC, pbQ;
vector<int> quadrado[MAXN], circulo[MAXN], diameterC, diameterQ;

void dfsC(int v){
    visited[v] = 1;
    
    if(pbC and (diameterC.empty() or furtherVertexC != diameterC.back() ) ) diameterC.push_back(furtherVertexC);
    
    for(int u : circulo[v])
        if(!visited[u]){
            distC[u] = max(distC[u], distC[v] + 1);
            furtherVertexC = (distC[u] > distC[furtherVertexC]? u : furtherVertexC);
            dfsC(u);
        }
}

void dfsQ(int v){
    visited[v] = 1;
    
    if(pbQ and (diameterQ.empty() or furtherVertexQ != diameterQ.back() ) ) diameterQ.push_back(furtherVertexQ);

    for(int u : quadrado[v])
        if(!visited[u]){
            distQ[u] = max(distQ[u], distQ[v] + 1);
            furtherVertexQ = (distQ[u] > distQ[furtherVertexQ]? u : furtherVertexQ);
            dfsQ(u);
        }
}

int main(){

    cin >> N >> M;

    for(int i = 1; i < N; i++){
        int a, b;
        cin >> a >> b;
        circulo[a].push_back(b);
        circulo[b].push_back(a);
    }

    for(int i = 1; i < M; i++){
        int x, y;
        cin >> x >> y;
        quadrado[x].push_back(y);
        quadrado[y].push_back(x);
    }

    dfsC(1);
    for(int i = 1; i <= N; i++){
        visited[i] = 0;
        distC[i] = 0;
    }

    pbC = 1;
    dfsC(furtherVertexC);

    for(int i = 1; i <= M; i++) visited[i] = 0;

    dfsQ(1);
    for(int i = 1; i <= M; i++){
        visited[i] = 0;
        distQ[i] = 0;
    }

    pbQ = 1;
    dfsQ(furtherVertexQ);

    /*for(auto u : diameterC) cout << u << " ";
    cout << endl;
    for(auto u : diameterQ) cout << u << " ";
    cout << endl;*/

    cout << diameterC[distC[furtherVertexC] / 2] << " " << diameterQ[distQ[furtherVertexQ] / 2] << endl;
}