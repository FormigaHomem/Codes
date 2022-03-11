#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int N, b;
    vector<pair<int, int> > a;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> b;
        a.push_back({b, 0});
    }

    sort(a.begin(), a.end() );
    for(int i = 0; i < N; i++) a.emplace(a.begin(), make_pair(a[a.size() - i - 1].first, count(a.begin(), a.end(), a[a.size() - 1 - i]) ) );
    a.resize(N);
    auto it = unique(a.begin(), a.end() );
    a.resize(distance(a.begin(), it) );

    for(pair<int, int> i : a) cout << i.first << " " << i.second << endl;

}
