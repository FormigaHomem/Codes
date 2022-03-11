#include <iostream>

int l[] = {0, -1, 0, 1};
int c[] = {1, 0, -1, 0};

int N, I, J, alunos[110][110], bandeiras = 1;
bool marked[110][100], not_to_pass[110][110];

using namespace std;

pair<int, int> grid(int x, int y){
    marked[x][y] = true;
    bool did_something = false;
    int a, b;

    for(int i = 0; i < 4; i++){
        a = x + l[i];
        b = y + c[i];
        if(a < 0 or a >= N or b < 0 or b >= N or alunos[a][b] < alunos[x][y] or marked[a][b]) continue;
        bandeiras++;
        did_something = true;
        grid(a, b);
    }

    if(!did_something) return {a, b};
    return {N - 1, N};

}

int main(){

    cin >> N >> I >> J;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) cin >> alunos[i][j];

    for(int i = I - 1; i < N; i++)
        for(int j = J - 1; j < N; j++){
            pair<int, int> a = grid(i, j); i = a.first; j = a.second - 1;
        }

    cout << bandeiras;

}
