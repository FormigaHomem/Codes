#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e4 + 10

using namespace std;

typedef pair<int, char> pic;

long N, M, pares;
char L;
vector<char> bota[MAXN];
map<pic, int> m;

char opposite(char c){
    return c == 'D'? 'E' : 'D';
}

int main(){_

    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> M >> L;
        m[pic(M, L) ]++;
        
        if(m[pic(M, opposite(L) ) ] ){
            pares++;
            m[pic(M, L) ]--; m[pic(M, opposite(L) ) ]--;
        }
    }

    cout << pares << endl;
}