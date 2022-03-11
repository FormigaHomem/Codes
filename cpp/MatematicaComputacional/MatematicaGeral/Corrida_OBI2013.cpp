#include <iostream>

using namespace std;

int main(){

    float id1, id2, dist1, dist2, vel1, vel2, tempo1, tempo2;

    cin >> id1 >> dist1 >> vel1 >> id2 >> dist2 >> vel2;

    tempo1 = dist1 / (vel1 / 3.6); 
    tempo2 = dist2 / (vel2 / 3.6);

    if(tempo2 < tempo1) cout << id2 << endl;
    else cout << id1 << endl;
}