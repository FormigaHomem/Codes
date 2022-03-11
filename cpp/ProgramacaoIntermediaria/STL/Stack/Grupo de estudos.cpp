#include <bits/stdc++.h>

using namespace std;

int main(){

    int N, b, c = 0;

    cin >> N;

    stack<int> a;

    for(int i = 0; i < N; i++){
        cin >> b;
        a.push(b);
        if(a.size() > 1 and b == c) a.pop();
        c = b;
    }
    cout << a.size();

}
