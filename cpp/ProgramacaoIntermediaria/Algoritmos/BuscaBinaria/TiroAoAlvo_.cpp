#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

long long C, R, T, X, Y, pontos;
vector<long> raios;

int main(){_

    cin >> C >> T;

    for(int i = 1; i <= C; i++){
        cin >> R;
        raios.push_back(R * R);
    }

    for(int i = 1; i <= T; i++){
        cin >> X >> Y;
        long long dist = X * X + Y * Y;
        int pos = lower_bound(raios.begin(), raios.end(), dist) - raios.begin();
        //cout << dist << " " << pos << endl;
        pontos += C - pos;
    }

    cout << pontos << endl;
}