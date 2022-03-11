#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 5e2 
#define f first
#define s second

using namespace std;

typedef pair<long, int> pli;

long N, pai[MAXN], peso[MAXN], grau[MAXN], dist;
pli existe[MAXN][MAXN];

struct Vertex{
    long u, v, in, w;
};

vector<Vertex> aresta;

int Find(int x){
    if(pai[x] == x) return x;
    return pai[x] = Find(pai[x]);
}

void join(int a, int b){
    a = Find(a), b = Find(b);

    if(peso[a] > peso[b]) pai[b] = a;
    else if(peso[b] > peso[a]) pai[a] = b;
    else{
        pai[b] = a;
        peso[a]++;
    }
}

int main(){_

    cin >> N;

    for(int i = 1; i <= N; i++){
        pai[i] = i;
        for(int j = 1; j <= N; j++){
            int a;
            cin >> a;
            if(j > i){
                existe[i][j].f = existe[j][i].f = a;
                aresta.push_back( {u: i, v: j, in: existe[i][j].s, w: a} );
            }
            else if(i > j){
                existe[i][j].s = existe[j][i].s = a; 
                aresta.push_back( {u: i, v: j, in: a, w: existe[i][j].f} );
                if(a){
                    join(i, j);
                    grau[i]++; grau[j]++;
                }
            }

            else existe[i][j] = existe[j][i] = {0, 0};
        }
    }

    sort(aresta.begin(), aresta.end(), [] (Vertex a, Vertex b) {return a.w < b.w;} );

    for(auto i : aresta){
        
        if(Find(i.u) != Find(i.v) ){
            //cout << i.u << " " << i.v << " " << i.in << " " << i.w << endl;
            join(i.u, i.v);
            grau[i.u]++; grau[i.v]++;
            dist += i.w;
        }

        else if(existe[i.u][i.v].s and grau[i.u] > 1 and grau[i.v] > 1){
            //cout << i.u << " " << i.v << " " << i.in << " " << i.w << " " << pai[i.u] << " " << pai[i.v] << endl;
            existe[i.u][i.v].s = existe[i.v][i.u].s = 0;
            grau[i.u]--; grau[i.v]--;
            dist += i.w;
        }
    }

    cout << dist << endl;
}