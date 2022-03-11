#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (long) 1e3 + 10
#define pb push_back

using namespace std;

long N, num;
vector<int> v;

long lis(){
    vector<int> pilha;
    
    for(int i : v){

        auto it = upper_bound(pilha.begin(), pilha.end(), i);

        if(it == pilha.end() ) pilha.pb(i);

        else *it = i;
    }
    
    return pilha.size();
}

int main(){_

    cin >> N ;

    for(int i = 1; i <= N; i++){
        cin >> num;
        v.pb(num);
    }

    cout << lis() << endl;
}