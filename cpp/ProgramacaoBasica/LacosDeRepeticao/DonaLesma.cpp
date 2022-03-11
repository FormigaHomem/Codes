#include <iostream>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int altura, sobe, desce, dias;

int main(){_

    cin >> altura >> sobe >> desce;


    while(altura > 0){
        altura -= sobe;
        dias++;
        if(altura > 0) altura += desce;
    }
    cout << dias << endl;
}
