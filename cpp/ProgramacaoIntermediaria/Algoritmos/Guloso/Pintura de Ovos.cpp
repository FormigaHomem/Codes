#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){

    pair<long int, long int> AG;
    pair<long double, long double> Sag;
    int N, a;
    Sag.first = 0;
    Sag.second = 0;

    cin >> N;

    string r = "";

    for(int i = 0; i < N; i++){
        cin >> AG.first >> AG.second;
        a = min(AG.first, AG.second);
        if(a == AG.first) r += "A";
        else r += "G";
        (r[i] == 'A')? Sag.first += AG.first : Sag.second += AG.second;
        if(abs(Sag.first - Sag.second) > 500){
            if(r[i] == 'A'){
                r.replace(i, 1, "G");
                Sag.first -= AG.first;
                Sag.second += AG.second;
            }
            else{
                r.replace(i, 1, "A");
                Sag.second -= AG.second;
                Sag.first += AG.first;
            }
        }
    }

    if(abs(Sag.first - Sag.second) > 500) cout << -1;
    else cout << r;

}
