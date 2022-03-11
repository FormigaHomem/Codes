#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    string n[N];
    for(int i = 0; i < N; i++){
        cin >> n[i];
    }
    vector<char> C;
    for(int i = 0; i < N; i++){
         for(int j = 0; j < n[i].size(); j++){
            C.push_back(n[i][j]);
         }
    }
    /*for(auto i:C){
        cout << i << " ";
    }
    cout << endl;*/

    for(int i = 0; i < 10; i++){
        char j = i + '0';
        cout << i << " - " << count(C.begin(), C.end(), j) << endl;
    }
}
