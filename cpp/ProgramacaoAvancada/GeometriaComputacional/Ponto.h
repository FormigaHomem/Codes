#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 101010

using namespace std;

typedef double T;

struct pt{
    T x, y;

    pt operator + (pt p) {return {x + p.x, y + p.y}; }
    pt operator - (pt p) {return {x - p.x, y - p.y}; }
    pt operator * (T d) {return {x * d, y * d}; }
    bool operator < (pt p) {return x < p.x or (x == p.x and y < p.y); }
    bool operator == (pt p) {return x == p.x and y == p.y;}
    bool operator != (pt p) {return !(pt{x, y} == p);}
};

// valor absoluto
T sq(pt p) {return p.x * p.x + p.y * p.y;}
T abs(pt p) {return sqrt(sq(p) );}

// ostream
ostream& operator << (ostream &os, pt p) {
    return os << "(" << p.x << "," << p.y << ")\n";
}

//produtos
T dot(pt v, pt w) {return v.x * w.x + v.y * w.y;} 
bool isPerp(pt v, pt w) {return dot(v, w) == 0;}
T cross(pt v, pt w) {return v.x * w.y - v.y * w.x;}
T ccw(pt a, pt b, pt c) {return cross(b - a, c - a);} //positive - counterclockwise; neutral - collinear; negative - clockwise

/*int main(){_

    //testes
    pt a{1, 0}, b{2, 3}, c{0, 5};

    cout << a << b << c << endl;
    cout << sq(b) << " " << abs(b) << endl;
    cout << a + b << b - c << a * 5 << endl;
    cout << dot(a, b) << " " << isPerp(a, c) << " " << cross(a, b) << " " << cross(b, c) << " " << cross(a, c) << " " << ccw(a, b, c) << endl;

}*/
