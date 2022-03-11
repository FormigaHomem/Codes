#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int N, K, U, winner[1010], a, x = 0;
    vector<int> cartela[1010];

    cin >> N >> K >> U;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < K; j++){
            cin >> a;
            cartela[i].push_back(a);
        }

    for(int i = 0; i < U; i++){
        cin >> a;
        for(int j = 0; j < N; j++){
            vector<int>::iterator it = remove(cartela[j].begin(), cartela[j].end(), a);
            cartela[j].resize(distance(cartela[j].begin(), it) );
        }
        if(any_of(cartela, cartela + N, [](vector<int> j) {return j.empty();} ) ) break;
    }
    for(int i = 0; i < N; i++) if(cartela[i].empty() ) winner[x++] = i + 1;

    for(int i = 0; i < x; i++) cout << winner[i] << " ";

}
