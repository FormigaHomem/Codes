// idea 1: use knapsack to see what's better: put the white piece in an available position or don't.
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 2e1
#define f first
#define s second

using namespace std;

typedef pair<int, int> pii;

long L, C, P, a, b, game_board[MAXN][MAXN], l[] = {1, -1, 0, 0}, c[] = {0, 0, 1, -1};
vector<pii> available_position, pretas;

int verifyNeighbors(int x, int y){
    return (game_board[x][y] != 2 and game_board[x + 1][y] != 2 and game_board[x - 1][y] != 2 and game_board[x][y + 1] != 2 and game_board[x][y - 1] != 2? 1 : 0);
}

int verifyLimits(int x, int y){
    return (x <= L and x >= 1 and y <= C and y >= 1 and !game_board[x][y]);
}

long knapsack(int id){

    if(id >= available_position.size() ) return 0;

    long dont_use = knapsack(id + 1);
    int x = available_position[id].f, y = available_position[id].s;

    if(verifyNeighbors(x, y) ){
        game_board[x][y] = 2;
        long use = 1 + knapsack(id + 1);
        game_board[x][y] = 0;

        return max(dont_use, use);
    }

    return dont_use;
}

int main(){

    cin >> L >> C >> P;

    for(int i = 1; i <= P; i++){
        cin >> a >> b;
        game_board[a][b] = 1;

        pretas.push_back( {a, b} );
    }

    for(auto i : pretas){
        int a = i.f, b = i.s;

        for(int j = 0; j < 4; j++){
            int x = a + l[j], y = b + c[j];

            if(verifyLimits(x, y) ) {
                available_position.push_back( {x, y} );
                game_board[x][y] = 3;
            }
        }
    }

    cout << knapsack(0) << endl;
}