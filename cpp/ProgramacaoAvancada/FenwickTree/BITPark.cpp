#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 3010101
#define INF 0x3f3f3f3f
#define LOG 20
#define f first
#define s second
#define lsb(x) x & (-x)
#define endl "\n"

using namespace std;

long N, E, PlayersA[MAXN], PlayersB[MAXN], posA[MAXN], posB[MAXN], invalidPos, goalsA, goalsB;

void updateA(int x, int k){
    for(;x < MAXN; x += lsb(x) ) PlayersA[x] += k;
}

long countPlayersA(int x){
    long ret = 0;
    for(;x > 0; x -= lsb(x) ) ret += PlayersA[x];
    return ret;
}

void updateB(int x, int k){
    for(;x > 0; x -= lsb(x) ) PlayersB[x] += k;
}

long countPlayersB(int x){
    long ret = 0;
    for(;x < MAXN; x += lsb(x) ) ret += PlayersB[x];
    return ret;
}

int main(){
    fastio

    while(cin >> N >> E, E){
        for(int i = 1; i <= N / 2; i++){
            cin >> posA[i];
            updateA(++posA[i], 1);
        }

        for(int i = 1; i <= N / 2; i++){
            cin >> posB[i];
            updateB(++posB[i], 1);
        }

        while(E--){
            char event;
            cin >> event;

            if(event == 'I'){
                char x; int i;
                cin >> x >> i;
                
                if(x == 'A' and countPlayersB(posA[i] + 1) < ceil( (float) N / 11) ) invalidPos = 1;
                else if(x == 'B' and countPlayersA(posB[i] - 1) < ceil( (float) N / 11) ) invalidPos = 1;
            }

            else if(event == 'M'){
                char x; int i, X;
                cin >> x >> i >> X;
                
                if(x == 'A'){
                    updateA(posA[i], -1);
                    updateA(posA[i] = ++X, 1);
                }

                else{
                    updateB(posB[i], -1);
                    updateB(posB[i] = ++X, 1);
                }
            }

            else if(event == 'P'){
                char x; int i;
                cin >> x >> i;

                if(x == 'A' and countPlayersB(posA[i] + 1) < ceil( (float) N / 11) ) invalidPos = 1;
                else if(x == 'B' and countPlayersA(posB[i] - 1) < ceil( (float) N / 11) ) invalidPos = 1;
            }

            else if(event == 'G'){
                char x;
                cin >> x;

                if(x == 'A'){
                    if(not invalidPos) goalsB++;
                    else invalidPos = 0;
                }

                else{
                    if(not invalidPos) goalsA++;
                    else invalidPos = 0;
                }
            }

            else if(invalidPos) invalidPos = 0;
        }

        cout << goalsA << " X " << goalsB << endl;

        for(int i = 1; i < MAXN; i++) PlayersA[i] = PlayersB[i] = posA[i] = posB[i] = 0;
        invalidPos = goalsA = goalsB = 0;
    }
}