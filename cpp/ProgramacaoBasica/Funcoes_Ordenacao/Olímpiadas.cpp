#include <iostream>
#include <algorithm>
using namespace std;

struct Pais{
    int O;
    int P;
    int B;
    int id;
};

int F(Pais a[], Pais b, int N, int j){
    static int x = N - 1;
    static int temp = N - 1;
    if(temp != b.id){
        x = N - 1;
        temp = b.id;
    }
    if(a[x].id == b.id){
        if(j == 0) return a[x].O++;
        else if(j == 1) return a[x].P++;
        else return a[x].B++;
    }
    --x;
    return F(a, b, N, j);
}

bool f(Pais a, Pais b){
    if(a.O != b.O){
        return a.O > b.O;
    }
    if(a.P != b.P){
        return a.P > b.P;
    }
    if(a.B != b.B){
        return a.B > b.B;
    }
    return a.id < b.id;
}

int main(){

    int N, M, x = 0;

    cin >> N >> M;

    Pais ID[N], P[M][3];

    for(int i = 0; i < N; i++){
        ID[i].id = i + 1;
        ID[i].O = 0;
        ID[i].P = 0;
        ID[i].B = 0;
    }

    for(int i = 0; i < M; i++){
        for(int j = 0; j < 3; j++){
            cin >> P[i][j].id;
            F(ID, P[i][j], N, j);
        }
    }

    sort(ID, ID + N, f);

     for(int i = 0; i < N; i++){
        cout << ID[i].id << " ";
    }

}
