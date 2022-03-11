#include <iostream>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int tabuleiro[20][20], l[] = {1, -1, 0, 0, 1, 1, -1, -1}, c[] = {0, 0, 1, -1, 1, -1, 1, -1};

bool pretas(int x, int y){
    
    for(int i = 0; i < 8; i++){
        int a = x + l[i], b = y + c[i], sequencia = 1;
        for(int j = 0; j < 4; j++){
            if(a < 1 or a > 15 or b < 1 or b > 15 or tabuleiro[a][b] != 1) break;
            
            sequencia++;
            a += l[i]; b += c[i];
        }
        if(sequencia >= 5) {
            cout << 1 << endl;
            return true;
        }
    }
    return false;
}

bool brancas(int x, int y){
    
    for(int i = 0; i < 8; i++){
        int a = x + l[i], b = y + c[i], sequencia = 1;
        for(int j = 0; j < 4; j++){
            if(a < 1 or a > 15 or b < 1 or b > 15 or tabuleiro[a][b] != 2) break;

            sequencia++;
            a += l[i]; b += c[i];
        }
        if(sequencia >= 5) {
            cout << 2 << endl;
            return true;
        }
    }
    return false;
}

int main(){_

    for(int i = 1; i <= 15; i++)
        for(int j = 1; j <= 15; j++) cin >> tabuleiro[i][j];

    for(int i = 1; i <= 15; i++)
        for(int j = 1; j <= 15; j++)
            if(tabuleiro[i][j] == 1) 
                if(pretas(i, j) ) return 0;
    
    for(int i = 1; i <= 15; i++)
        for(int j = 1; j <= 15; j++)
            if(tabuleiro[i][j] == 2) 
                if(brancas(i, j) ) return 0;
    cout << 0;
}