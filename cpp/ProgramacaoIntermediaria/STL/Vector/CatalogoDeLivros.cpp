#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 101010
#define INF 0x3f3f3f3f
#define LOG 20
#define endl '\n'
#define lsb(x) x & (-x)
#define f first
#define s second

using namespace std;

int A, B, C, D, E, K;
long long ans;
vector<vector<int> > book(6);
vector<int> combination, temp(10);

int main(){
    fastio

    for(int i = 1; i <= 5; i++){
        int x;
        cin >> x;
        book[i].resize(x);
        temp.resize(x);

        for(int j = 0; j < x; j++){
            int y;
            cin >> y;
            temp[j] = y;
        }

        book[i] = temp;
    }

    cin >> K;

    for(auto a : book[1])
        for(auto b : book[2])
            for(auto c : book[3])
                for(auto d : book[4])
                    for(auto e : book[5])
                        combination.push_back(a + b + c + d + e);
    sort(combination.begin(), combination.end(), [] (int a, int b) { return a > b;});

    for(int i = 0; i < K; i++) ans += combination[i];
    cout << ans << endl;
}