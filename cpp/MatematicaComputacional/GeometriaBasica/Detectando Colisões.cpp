#include <iostream>

using namespace std;

bool aux(int a, int b, int c){
    return (c >= a and c <= b? true : false);
}

bool intersect(long int v1[], long int v2[]){
    if(aux(v1[1], v2[1], v1[0]) or aux(v1[1], v2[1], v2[0]) or aux(v1[0], v2[0], v1[1]) or aux(v1[0], v2[0], v2[1]) ) return true;
    else return false;
}

int main(){
    long int x[2], y[2], x2[2], y2[2];
    for(int i = 0; i < 2; i++) cin >> x[i] >> y[i] >> x2[i] >> y2[i];

    if( intersect(x, x2) and intersect(y, y2) ) cout << 1;
    else cout << 0;
}
