#include <iostream>
#include <queue>
#include <vector>
#include <functional>

#define f first
#define s second
#define t top()
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

typedef pair<int, pair<int, int> > pii;
typedef long long int ll;

bool ord(pii a, pii b){
    if(a.f != b.f) return a.f > b.f;
    return a.s.s > b.s.s;
}

bool ordp(pii a, pii b){
    return a.s.s > b.s.s;
}

void print(priority_queue<pii, vector<pii>, function<bool(pii, pii)> > phone){
    priority_queue<pii, vector<pii>, function<bool(pii, pii)> > print(ordp);
    while(!phone.empty() ){
        print.push(phone.t);
        phone.pop();
    }
    while(!print.empty() ) {
        cout << print.t.s.s << " " << print.t.s.f << endl;
        print.pop();
    }
}

int main(){_

    ll L, N, a;
    priority_queue<pii, vector<pii>, function<bool(pii, pii)> > phone(ord);

    cin >> N >> L;

    for(int i = 1; i <= N; i++) phone.push({0, {0, i} });
    for(int i = 0; i < L; i++){
        cin >> a;
        pii aux;
        aux = {phone.t.f + a, {phone.t.s.f + 1, phone.t.s.s} };
        phone.pop();
        phone.push(aux);
    }

    print(phone);

}
