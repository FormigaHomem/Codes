#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (long) 1e6 + 10
#define INF 0x3f3f3f3f

using namespace std;

long N, S, T, Up, Down, dist[MAXN];

long bfs(){
    for(int i = 1; i <= N; i++) dist[i] = INF;
    dist[S] = 0;
    queue<int> q;
    q.push(S);

    while(q.size() ){
        int v = q.front(); q.pop();

        if(v + Up <= N and dist[v + Up] == INF){
            dist[v + Up] = min(dist[v + Up], dist[v] + 1);
            q.push(v + Up);
        }

        else if(v - Down >= 1 and dist[v - Down] == INF){
            dist[v - Down] = min(dist[v - Down], dist[v] + 1);
            q.push(v - Down);
        }
    }  

    return dist[T];
}

int main(){

    cin >> N >> S >> T >> Up >> Down;

    long ans = bfs();
    if(ans >= INF) cout << "use the stairs\n";
    else cout << ans << endl;
}