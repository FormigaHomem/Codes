#include <iostream>
#include <set>

using namespace std;

int main(){

    int N, b;
    set<int> a;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> b;
        a.insert(b);
    }

    cout << a.size();

}
