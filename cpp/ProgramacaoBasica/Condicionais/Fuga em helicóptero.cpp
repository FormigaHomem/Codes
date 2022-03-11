#include <bits/stdc++.h>

#define brk '\n'

using namespace std;

int pos[5], i, j, len = 9;

int bo[12][12]= {   {7,8,0,4,0,0,1,2,0},
                    {6,0,0,0,7,5,0,0,9},
                    {0,0,0,6,0,1,0,7,8},
                    {0,0,7,0,4,0,2,6,0},
                    {0,0,1,0,5,0,9,3,0},
                    {9,0,4,0,6,0,0,0,5},
                    {0,7,0,3,0,0,0,1,2},
                    {1,2,0,0,0,7,4,0,0},
                    {0,4,9,2,0,6,0,0,7}     };

bool find_empty() {
    for(i = 0; i < len; i++)
        for(j = 0; j < len; j++)
            if(bo[i][j] == 0){
                pos[0] = i; pos[1] = j;
                return true;
            }
    return false;
}

int valid(int num) {
    // Linha
    for(j = 0; j < len; j++)
        if(bo[pos[0] ][j] == num and pos[1] != j) return 0;

    // Coluna
    for(i=0; i<len; ++i)
        if(bo[i][pos[1] ] == num and pos[0] != i) return 0;

    // Quadrado
    int bx = pos[1] / 3, by = pos[0] / 3;
    for(i = by; i < by + 3; i++)
        for(j = bx; j < bx + 3; j++)
            if(bo[i][j] == num and i != pos[0] and j != pos[1]) return 0;

    return 1;
}

bool solve() {
    bool find_e = find_empty();
    int lin, col;

    if(!find_e) return true;
    else{
        lin = pos[0];
        col = pos[1];
    }

    for(int n = 1; n < 10; n++) {
        if(valid(n) )
            bo[lin][col] = n;
            if (solve() ) return true;
            bo[lin][col] = 0;
    }
    return false;
}

void print_board() {
    for(i = 0; i < len; i++) {
        if(i % 3 == 0 and i != 0) puts("- - - - - - - - - - -");

        for(j = 0; j < len; j++) {
            if(j % 3 == 0 and j != 0) cout << "| ";
            if(j == 8) cout << bo[i][j] << brk;
            else cout << bo[i][j] << ' ';
        }
    }
    puts("");

    return;
}



int main() {
    print_board();
    solve();
    print_board();
    return 0;
}

/*#include <iostream>

using namespace std;

int main(){

    int H, P, F, D;

    cin >> H >> P >> F >> D;

    if(D == 1){
        if(H > F and P > F){
            if(H < P) cout << 'S';
            else cout << 'N';
        }

        else if(H > F or P > F){
            if(H > P) cout << 'S';
            else cout << 'N';
        }

        else{
            if(H < P) cout << 'S';
            else cout << 'N';
        }
    }
    else{
        if(H < F and P < F){
            if(H > P) cout << 'S';
            else cout << 'N';
        }

        else if(H < F or P < F){
            if(H < P) cout << 'S';
            else cout << 'N';
        }

        else{
            if(H > P) cout << 'S';
            else cout << 'N';
        }
    }
}*/
