#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 101010
#define INF 0x3f3f3f3f
#define LOG 20
#define lsb(x) x & (-x)
#define f first
#define s second
#define endl '\n'

using namespace std;

int N;

int main(){
    fastio
    
    while(cin >> N){
        int type, x;
        queue<int> q;
        stack<int> s;
        priority_queue<int> pq;

        pair<int, string> isQ = {1, "queue"}, isS = {1, "stack"}, isPq = {1, "priority queue"};

        while(N--){
            cin >> type >> x;
            
            if(type == 1){
                q.push(x);
                s.push(x);
                pq.push(x);
            }

            else{
                if(!isQ.f or x != q.front() ) isQ.f = 0;
                else q.pop();
                
                if(!isS.f or x != s.top() ) isS.f = 0;
                else s.pop();

                if(!isPq.f or x != pq.top() ) isPq.f = 0;
                else pq.pop();
            }
        }
        
        if(isQ.f + isS.f + isPq.f == 0) cout << "impossible\n";
        else if(isQ.f + isS.f + isPq.f > 1) cout << "not sure\n";
        else{
            pair<int, string> ans = max( {isQ, isS, isPq} );
            cout << ans.s << endl;
        }
    }
}