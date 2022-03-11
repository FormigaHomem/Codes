//Solve por dfs
#include <iostream>
#include <vector>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int)10e3+10

using namespace std;

int N, M, a, b, times = 0;
vector<int> amigos[MAXN];
bool visited[MAXN];

void dfs(int x){
    visited[x] = true;

    for(int i : amigos[x])
        if(!visited[i]) dfs(i);

    return;
}

int main(){_

    cin >> N >> M;

    for(int i = 0; i < M; i++){
        cin >> a >> b;
        amigos[a].push_back(b);
        amigos[b].push_back(a);
    }

    for(int i = 1; i <= N; i++)
        if(!visited[i]){
            dfs(i);
            times++;
        }

    cout << times << endl;
}
/*/Solve por Union-Find
#include <iostream>

using namespace std;

#define MAXN (int) 1e3+10

int N, M, a, b, amigo[MAXN], popularidade[MAXN], times;

int Find(int x){
    if(amigo[x] == x) return x;
    return amigo[x] = Find(amigo[x]);
}

void join(int a, int b){

    a = Find(a);
    b = Find(b);

    if(popularidade[a] > popularidade[b]) amigo[b] = a;
    else if(popularidade[b] > popularidade[a]) amigo[a] = b;
    else{
        amigo[b] = a;
        popularidade[a]++;
    }

}

int main(){

    cin >> N >> M;

    for(int i = 0; i < N; i++) amigo[i] = i;

    for(int i = 0; i < M; i++){
        cin >> a >> b;
        join(a, b);
    }

    for(int i = 0; i < N; i++)
        if(Find(i) == i) times++;

    cout << times;
}*/
