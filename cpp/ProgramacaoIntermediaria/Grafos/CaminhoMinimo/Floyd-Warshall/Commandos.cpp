#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e2 + 10

using namespace std;

long T, t = 1, N, R, S, D, dist[MAXN], meeting_dist[MAXN], visited[MAXN], ans;
vector<int> road[MAXN];

void bfsIni(){
    queue<int> q;
    q.push(S);

    dist[S] = 0;

    while(q.size() ){
        int v = q.front();
        q.pop();

        visited[v] = 1;

        for(auto u : road[v])
            if(!visited[u]){
                dist[u] = min(dist[u], dist[v] + 1);
                q.push(u);
            }
    }

    for(int i = 0; i < N; i++) visited[i] = 0;
}

void bfsFim(){
    queue<int> q;
    q.push(D);

    meeting_dist[D] = 0;

    while(q.size() ){
        int v = q.front();
        q.pop();

        visited[v] = 1;

        for(auto u : road[v])
            if(!visited[u]){
                meeting_dist[u] = min(meeting_dist[u], meeting_dist[v] + 1);
                q.push(u);
            }
    }
}

int main(){

    cin >> T;

    while(T--){
        cin >> N >> R;

        for(int i = 1; i <= R; i++){
            int u, v;
            
            cin >> u >> v;

            road[u].push_back(v);
            road[v].push_back(u);
            visited[u] = visited[v] = 0; dist[u] = dist[v] = meeting_dist[u] = meeting_dist[v] = (long) 1e9;
        }
        
        cin >> S >> D;

        bfsIni();
        bfsFim();

        for(int i = 0; i < N; i++) ans = max(ans, dist[i] + meeting_dist[i]);

        cout << "Case " << t++ << ": " << ans << endl;

        for(int i = 0; i < N; i++) road[i].clear();
        ans = 0;
    }

}