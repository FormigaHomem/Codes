#include <iostream>
#include <map>
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

map<string, int> kills;
map<string, bool> killed;

int main(){
    boost;
    string aux1, aux2;

    while(cin >> aux1 >> aux2){
        if(!killed[aux1]) kills[aux1] += 1;
        killed[aux2] = true;
    }

    cout << "HALL OF MURDERERS\n";
    for(pair<string, int> i : kills)
        if(!killed[i.first] ) cout << i.first << " " << i.second << endl;

}
