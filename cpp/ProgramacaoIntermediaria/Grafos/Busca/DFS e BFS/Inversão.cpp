#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (long) 1e4 + 10
#define INF 0x3f3f3f3f

using namespace std;

long T, A, B, dist[MAXN];

long bfs(){
    
    long v = A;
    
    queue<long> q;
    q.push(v);

    dist[v] = 0;

    while(!q.empty() and v != B){
        v = q.front(); q.pop();

        string s = to_string(v), r;
        reverse_copy(s.begin(), s.end(), r.begin() );
        long t = stoi(r);
        
        if(dist[t] == INF){
            dist[t] = dist[v] + 1;
            q.push(t);      
        }
        
        if(dist[v + 1] == INF){
            dist[v + 1] = dist[v] + 1;
            q.push(v + 1);
        }
        
    }

    return dist[B];
}

int main(){_

    cin >> T;

    while(T--){
        memset(dist, INF, sizeof(dist) );

        cin >> A >> B;

        cout << bfs() << endl;
    }

}