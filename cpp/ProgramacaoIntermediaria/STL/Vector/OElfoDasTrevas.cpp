#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 101010
#define INF 0x3f3f3f3f
#define LOG 20
#define endl '\n'
#define lsb(x) x & (-x)
#define f first
#define s second

using namespace std;

struct Rena{
    int idade, peso;
    float altura;
    string nome;
};

int t, T, N, M;
long long ans;

int main(){
    fastio

    cin >> T;

    while(T--){
        cin >> N >> M;

        vector<Rena> rena(N);
        for(int i = 0; i < N; i++)
            cin >> rena[i].nome >> rena[i].peso >> rena[i].idade >> rena[i].altura;
        sort(rena.begin(), rena.end(), [] (Rena a, Rena b) {
            if(a.peso != b.peso) return a.peso > b.peso;
            else{
                if(a.idade != b.idade) return a.idade < b.idade;
                else{
                    if(a.altura != b.altura) return a.altura < b.altura;
                    else return a.nome < b.nome;
                }
            }
        });

        cout << "CENARIO {" << ++t << "}\n";
        for(int i = 0; i < M; i++) cout << i + 1 << " - " << rena[i].nome << endl;
    }
}