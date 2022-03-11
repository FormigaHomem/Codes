#include <iostream>
#include <vector>
#include <algorithm>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define f first
#define s second

using namespace std;

int main(){

    int P, S, index = 0;
    pair<int, int> aux[6000];
    vector<pair<int , int> > sorvete;

    cin >> P >> S;

    for(int i = 0; i < S; i++)  cin >> aux[i].f >> aux[i].s;

    sort(aux, aux + S);

    sorvete.push_back(aux[0]);

    for(int i = 1; i < S; i++){
        if(sorvete[index].f >= aux[i].f and sorvete[index].f <= aux[i].s and sorvete[index].s >= aux[i].f and sorvete[index].s <= aux[i].s) swap(sorvete[index], aux[i]);

        else if(aux[i].f < sorvete[index].f and aux[i].s >= sorvete[index].f and aux[i].s <= sorvete[index].s) swap(sorvete[index].f, aux[i].f);

        else if(aux[i].s > sorvete[index].s and aux[i].f >= sorvete[index].f and aux[i].f <= sorvete[index].s) swap(sorvete[index].s, aux[i].s);

        else if( !(aux[i].f >= sorvete[index].f and aux[i].f <= sorvete[index].s and aux[i].s >= sorvete[index].f and aux[i].s <= sorvete[index].s) ){
            sorvete.push_back(aux[i]);
            index++;
        }
    }

    for(pair<int, int> i : sorvete) cout << i.f << " " << i.s << endl;
}
