#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 1010

using namespace std;

long N, M, visited[MAXN], match[MAXN];
vector<long> g[MAXN];

int augmenting(int v){
    if(visited[v]) return 0;

    visited[v] = 1;

    for(auto u : g[v]){
        if(match[u] == -1 or augmenting(match[u]) ){
            match[u] = v;
            return 1;
        }
    }

    return 0;
}

int main(){
    // main stuff
}