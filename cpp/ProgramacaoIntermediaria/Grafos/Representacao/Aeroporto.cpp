#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

bool ord(pair<int, int> a, pair<int, int> b){
    if(a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

int main(){

    int A, V, teste = 1;

    while(cin >> A >> V, V){
        vector<pair<int, int> > qnt(A + 5);

        for(int i = 1; i <= A; i++) {
            qnt[i].second = i;
            qnt[i].first = 0;
        }

        for(int i = 0; i < V; i++){
            int a, b;
            cin >> a >> b;
            qnt[a].first++;
            qnt[b].first++;
        }

        sort(qnt.begin() + 1, qnt.end(), ord);

        cout << "Teste " << teste << endl;

        if(qnt[1].first != qnt[2].first) cout << qnt[1].second;

        else {
            cout << qnt[1].second << " ";
            int i = 1;
            while(i++, qnt[i].first == qnt[i - 1].first) cout << qnt[i].second << " ";
        }
        teste++;
        cout << endl << endl;
    }

}
