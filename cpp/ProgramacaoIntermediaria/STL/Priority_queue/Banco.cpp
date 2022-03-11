#include <iostream>
#include <queue>
#include <vector>
#include <functional>

#define f first
#define s second
#define t top()
#define fr front()
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

typedef pair<int, int> pii;
typedef long long int ll;

int main(){_

    ll C, N, fails = 0, espera;
    priority_queue<int, vector<int>, greater<int> > cashier;
    pii a;

    cin >> C >> N;

    for(int i = 0; i < C; i++) cashier.push(0);
    for(int i = 0; i < N; i++){
        cin >> a.f >> a.s;
        espera = cashier.t - a.f;

        if(espera > 20) fails++;
        ll aux;
        if(a.f > cashier.t) aux = a.f + a.s;
        else aux = cashier.t + a.s;
        cashier.pop();
        cashier.push(aux);
    }

    cout << fails;
}
