#include<bits/stdc++.h>
#include "Ponto.h"

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 101010

using namespace std;

vector<pt> CH(vector<pt> v){
    sort(v.begin(), v.end() );
    pt p1 = v[0], p2 = v.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for(int i = 1; i < v.size(); i++){
        if(i == v.size() - 1 or ccw(p1, v[i], p2) < 0){
            while(up.size() >= 2 and ccw(up[up.size() - 2], up[up.size() - 1], v[i]) > 0 ) up.pop_back();
            up.push_back(v[i]);
        }

        if(i == v.size() - 1 or ccw(p1, v[i], p2) > 0){
            while(down.size() >= 2 and ccw(down[down.size() - 2], down[down.size() - 2], v[i]) < 0) down.pop_back();
            down.push_back(v[i]);
        }
    }

    vector<pt> hull = up;
    for(int i = down.size() - 2; i > 0; i--) hull.push_back(down[i]);
    return hull;
};

int main(){_
    long N;
    cin >> N;
    vector<pt> v(N);

    for(int i = 0; i < N; i++){
        T x, y;
        cin >> x >> y;
        v[i] = pt{x, y};
    }

    vector<pt> h = CH(v);

    for(auto i : h) cout << i << endl;
}