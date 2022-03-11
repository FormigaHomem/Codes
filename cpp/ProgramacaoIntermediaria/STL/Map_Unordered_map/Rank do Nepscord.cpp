#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e3 + 10
#define f first
#define s second

using namespace std;

typedef pair<int, pair<int, int> > piii;
typedef pair<string, piii> psiii;

int N, K, M, coloc = 1;
string U;

map<string, piii> user;

bool ord(psiii a, psiii b){
    if(a.s.f != b.s.f) return a.s.f < b.s.f;
    return a.f > b.f;
}

void transfer(priority_queue<psiii, vector<psiii>, function<bool(psiii, psiii) > > &pq){
    for(psiii i : user) pq.push(i);
}

int main(){_

    cin >> N >> K;

    for(int i = 0; i < N; i++){
        cin >> U >> M;
        if(M - user[U].s.s >= K or user[U].f == 0) user[U] = {user[U].f + 25, { (user[U].f + 25) / 100 + 1, M} };
    }

    priority_queue<psiii, vector<psiii>, function<bool(psiii, psiii) > > print(ord);

    transfer(print);

    cout << "--Rank do Nepscord--\n";

    while(!print.empty() and coloc <= 3){
        cout << "#" << coloc++ << ". " << print.top().f << "-Nivel " << print.top().s.s.f << endl;
        print.pop();
    }
    for(int i = coloc; i <= 3; i++) cout << "#" << i << ".\n";
}