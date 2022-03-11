#include <iostream>

using namespace std;

int N, place[110][110], a;
int main(){

    cin >> N;

    for(int k = 0; k < 2; k++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++){
                cin >> a;
                place[i][j] += a;
            }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cout << place[i][j] << " ";
        cout << endl;
    }

}
