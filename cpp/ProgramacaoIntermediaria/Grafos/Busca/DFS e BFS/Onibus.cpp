#include <iostream>
#include <vector>
#include <queue>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e4 + 10

using namespace std;

long int N, O, D, P, Q, onibus[MAXN];
bool visited[MAXN];
vector<long int> linha[MAXN];


long int bfs(long int ini){
    for(int i = 1; i<= N; i++) onibus[i] = MAXN;
    queue<int> q;
    q.push(ini);
    onibus[ini] = 0;
    while(q.front() != D){
        int v = q.front();
        q.pop();
        visited[v] = true;

        for(int i : linha[v])
            if(!visited[i]) {
                onibus[i] = min(onibus[i], onibus[v] + 1);
                q.push(i);
            }
    }
    return onibus[D];
}

int main(){_

    cin >> N >> O >> D;

    for(int i = 1; i < N; i++){
        cin >> P >> Q;
        linha[P].push_back(Q);
        linha[Q].push_back(P);
    }

    cout << bfs(O);
}
