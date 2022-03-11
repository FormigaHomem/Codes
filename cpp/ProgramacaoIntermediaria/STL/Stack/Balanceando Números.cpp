#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000010

int abre, fecha, A, seq[MAXN];

int main(){
    cin >> abre >> fecha >> A;
    for(int i = 0; i < A; i++) cin >> seq[i];
    stack<int> pr;
    for(int j : seq){
      if(j == abre) pr.push(1);
      else if(j == fecha){
        if(pr.empty()){
          cout << "Desbalanceada!" << endl;
          return 0;
        }
        pr.pop();
      }
    }
    if(pr.empty() ) cout << "Balanceada!" << endl;
    else cout << "Desbalanceada!" << endl;
}
