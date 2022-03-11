#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int x, y, x2, y2;

    cin >> x >> y >> x2 >> y2;

    cout << abs(x2 - x) + abs(y2 - y);
}
