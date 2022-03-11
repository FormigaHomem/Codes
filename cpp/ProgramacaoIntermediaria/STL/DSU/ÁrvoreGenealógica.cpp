#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 310

using namespace std;

long N, M, ans;
map<string, string> pai;
map<string, int> peso;
vector<pair<string, string> > adjs;
string u, lig, v;

string Find(string x){
    if(pai[x] == x) return x;

    return pai[x] = Find(pai[x]);
}

void join(string a, string b){
    a = Find(a), b = Find(b);

    if(peso[a] > peso[b]) pai[b] = a;
    else if(peso[b] > peso[a]) pai[a] = b;
    else{
        pai[b] = a;
        peso[a]++;
    }
}

int main(){_

    cin >> N >> M;

    for(int i = 1; i <= M; i++){
         cin >> u >> lig >> v;
        pai[u] = u; pai[v] = v;
        peso[u] = peso[v] = 0;
        adjs.push_back( {u, v} );
    }

    for(auto i : adjs) join(i.first, i.second);

    for(auto it = pai.begin(); it != pai.end(); it++)
        if(Find(it->first) == it->first) ans++;
    
    cout << ans << endl;
}