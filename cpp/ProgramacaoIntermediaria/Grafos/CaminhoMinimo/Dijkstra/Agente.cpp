#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (ll) 1e4 + 10
#define INF 0x3f3f3f3f
#define f first
#define s second

using namespace std;

typedef pair<long, int> pli;
typedef long long ll;

ll N, C, S, B, start, finish, dist[MAXN], distB[MAXN], bandit[MAXN];
vector<pli> road[MAXN], roadB[MAXN];

// dijkstra: O(MlogM) => maximo = 1,5 * 10^7
void Dijkstra(){
    for(int i = 1; i <= N; i++) dist[i] = INF;
    priority_queue<pli, vector<pli>, greater<pli> > fila;
    fila.emplace(0, start);
    dist[start] = 0;

    while(!fila.empty() ){
        ll v = fila.top().s, d = fila.top().f;
        fila.pop();

        if(d > dist[v]) continue;

        for(auto i : road[v]){
            ll w = i.f, u = i.s;

            if(dist[u] > d + w){
                dist[u] = d + w;
                fila.emplace(dist[u], u);
            }
        }

    }
}

// dijkstraB: O(MlogM) => maximo = 1,5 * 10^7
void DijkstraB(){

    for(int i = 1; i <= N; i++) distB[i] = INF;
    priority_queue<pli, vector<pli>, greater<pli> > fila;
    fila.emplace(0, finish);
    distB[finish] = 0;

    while(!fila.empty() ){
        ll v = fila.top().s, d = fila.top().f;
        fila.pop();

        if(d > distB[v]) continue;

        for(auto i : roadB[v]){
            ll w = i.f, u = i.s;

            if(distB[u] > d + w){
                distB[u] = d + w;
                fila.emplace(distB[u], u);
            }
        }

    }
}

int main(){

    cin >> N >> C >> S >> B;

    for(int i = 1; i <= C; i++){
        ll a, b, v;

        cin >> a >> b >> v;

        road[a].emplace_back(v, b); 
        road[b].emplace_back(v, a); 

        roadB[a].emplace_back(v, b); 
        roadB[b].emplace_back(v, a); 
    }
    
    for(int i = 1; i <= S; i++){
        ll a, b, v;

        cin >> a >> b >> v;

        roadB[a].emplace_back(v, b); 
        roadB[b].emplace_back(v, a); 
    }

    for(int i = 1; i <= B; i++){
        int pos;
        cin >> pos;
        bandit[i] = pos;
    }

    cin >> start >> finish;

    Dijkstra();
    DijkstraB();

    int ans = 0;
    for(int i = 1; i <= B; i++)
        if(distB[bandit[i] ] <= dist[finish]) ans++;

    cout << ans << endl;
}