#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    int a, N, M;

    cin >> N;

    set<int> menor, maior;

    for(int i = 0; i < N; i++){
        cin >> a;
        maior.insert(a);
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> a;
        menor.insert(a);
    }

    if(includes(maior.begin(), maior.end(), menor.begin(), menor.end() ) ) cout << true;
    else cout << false;

}
