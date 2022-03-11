#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 101010

using namespace std;

typedef double T;

struct pt{
    T x, y;
    
    pt operator - (pt p) {return {x - p.x, y - p.y}; }
    bool operator == (pt p) {return x == p.x and y == p.y;}
    bool operator != (pt p) {return !(pt{x, y} == p);}
    

    T sq (void) {return x * x + y * y;}
    T abs (void) {return sqrt(sq() );}
    T cross (pt p) {return x * p.y - y * p.x;}
};

bool operator < (const pt a, const pt b) {return a.x < b.x or (a.x == b.x and a.y < b.y);}
T ccw(pt a, pt b, pt c) {return (b - a).cross(c - a); }

long N;
vector<pt> CH(vector<pt> v){
    sort(v.begin(), v.end());

    pt p1 = v[0], p2 = v.back();
    vector<pt> up, down;

    up.push_back(p1); down.push_back(p1);

    for(int i = 1; i < v.size(); i++){
        if(i == v.size() - 1 or ccw(p1, v[i], p2) ){
            while(up.size() >= 2 and ccw(up[up.size() - 2], up[up.size() - 1], v[i]) > 0) up.pop_back();
            up.push_back(v[i]);
        }

        if(i == v.size() - 1 or ccw(p1, v[i], p2) ){
            while(down.size() >= 2 and ccw(down[down.size() - 2], down[down.size() - 1], v[i]) < 0) down.pop_back();
            down.push_back(v[i]);
        }
    }

    vector<pt> hull = up;

    for(int i = down.size() - 2; i > 0; i--) hull.push_back(down[i]);

    return hull;
}

int main(){_

    while(cin >> N, N){
        vector<pt> v(N);

        for(int i = 0; i < N; i++){
            T x, y; 
            cin >> x >> y;
            v[i] = pt{x, y};
        }

        vector<pt> h = CH(v);

        T ans = (h[h.size() - 1] - h[0]).abs();

        for(int i = 1; i < h.size(); i++){
            pt line = h[i] - h[i - 1];
            ans += line.abs();
        }
        
        cout.precision(2);
        cout << "Tera que comprar uma fita de tamanho " << fixed << ans << ".\n";
    }
}