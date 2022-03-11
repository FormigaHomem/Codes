#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> elevator;
    float a, b, weight = 0, people = 0;
    bool stop = false;

    while(cin >> a, !stop){
        people++;
        weight += a;
        if(!a or weight >= 560 or people == 7) {
            if(!a) people--;
            cout << people << endl;
            cout.precision(1);
            cout << fixed << weight << endl;
            stop = true;
            if(!a) return 0;
        }
    }

}
