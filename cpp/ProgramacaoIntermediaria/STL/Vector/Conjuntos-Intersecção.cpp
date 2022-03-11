#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<int> A, B, intersect(10);
    vector<int>::iterator it;
    int a;


    for(int i = 0; i < 5; i++){
        cin >> a;
        A.push_back(a);
    }

    for(int i = 0; i < 5; i++){
        cin >> a;
        B.push_back(a);
    }

    sort(A.begin(), A.end() );
    sort(B.begin(), B.end() );

    it = set_intersection(A.begin(), A.end(), B.begin(), B.end(), intersect.begin() );

    intersect.resize(it - intersect.begin() );

    for(int i : intersect) cout << i << " ";
    //:)

}
