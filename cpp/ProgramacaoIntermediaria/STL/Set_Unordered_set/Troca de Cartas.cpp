#include <iostream>
#include <set>

using namespace std;

int main(){

    int A, B, C, x = 0, y = 0;
    set<int> a, b, c;

    cin >> A >> B;

    for(int i = 0; i < A; i++){
        cin >> C;
        a.insert(C);
    }

    for(int i = 0; i < B; i++){
        cin >> C;
        b.insert(C);
    }

    for(int i : b)
        if(a.find(i) == a.end() ) x++;

    for(int i : a)
        if(b.find(i) == b.end() ) y++;


    cout << min(x, y);

}
