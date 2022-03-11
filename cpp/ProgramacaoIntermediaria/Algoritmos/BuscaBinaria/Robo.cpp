#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e5 + 10
#define f first
#define s second
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;

long N, M, K, L, pos_x, pos_y, l[] = {0, 1, 0, -1}, c[] = {1, 0, -1, 0};
vector<pair<int, int> > obstaculos;

int main(){

    cin >> N >> M >> pos_x >> pos_y >> K >> L;

    for(int i = 1; i <= K; i++){
        int x, y;
        cin >> x >> y;
        obstaculos.push_back( {x, y} );
    }

    sort(obstaculos.begin(), obstaculos.end() );

    for(int i = 0; i < L; i++){
        cout << endl << pos_x << " " << pos_y << endl;
        if(l[i % 4]){
            if(l[i % 4] == 1){
                cout << "Baixo\n";
                auto it = lower_bound(obstaculos.begin(), obstaculos.end(), pii(pos_x, pos_y), [] (pii comp, pii search) {cout << comp.f << " " << comp.s << " " << search.f << " " << search.s << endl; return !(comp.s != search.s or comp.f <= search.f); } );
                int p = it - obstaculos.begin();
                (p == 0? p = 1 : p = p);
                if(it != obstaculos.end() ){
                    cout << obstaculos[p - 1].f << " " << obstaculos[p - 1].s << endl;
                    pos_x = max(obstaculos[p - 1].f - 1, 1);
                }
                else pos_x = N;
                cout << pos_x << endl;
                continue;
            }
            else{
                cout << "Cima\n";
                auto it = lower_bound(obstaculos.begin(), obstaculos.end(), pii(pos_x, pos_y), [] (pii comp, pii search) { return (comp.s == search.s and comp.f < search.f); } );
                int p = it - obstaculos.begin();
                (p == 0? p = 1 : p = p);
                if(it != obstaculos.end() ){
                    cout << obstaculos[p - 1].f << " " << obstaculos[p - 1].s << endl;
                    pos_x = min(obstaculos[p - 1].f + 1, int(N) );
                }
                else pos_x = 1;
                cout << pos_x << endl;
                continue;
            }
            
        }
        else{
            if(c[i % 4] == 1){
                cout << "Direita\n";
                auto it = lower_bound(obstaculos.begin(), obstaculos.end(), pii(pos_x, pos_y), [] (pii comp, pii search) {cout << comp.f << " " << comp.s << " " << search.f << " " << search.s << endl; return !(comp.f != search.f or comp.s <= search.s); } );
                int p = it - obstaculos.begin();
                if(it != obstaculos.end() ){
                    cout << obstaculos[p - 1].f << " " << obstaculos[p - 1].s << endl;
                    pos_y = max(1, obstaculos[p - 1].s - 1);
                }
                else pos_y = M;
                cout << pos_y << endl;
                continue;
            }
            else{
                cout << "Esquerda\n";
                auto it = lower_bound(obstaculos.begin(), obstaculos.end(), pii(pos_x, pos_y), [] (pii comp, pii search) { return (comp.f == search.f and comp.s < search.s); } );
                int p = it - obstaculos.begin();
                if(it != obstaculos.end() ){
                    cout << obstaculos[p - 1].f << " " << obstaculos[p - 1].s << endl;
                    pos_y = min(obstaculos[p - 1].s + 1, int(M) );
                }
                else pos_y = 1;
                cout << pos_y << endl;
                continue;
            }
        }
    }

    cout << pos_x << " " << pos_y << endl;
}