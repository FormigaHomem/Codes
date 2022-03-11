#include <iostream>

#define _ std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define MAXN (int)3e2

int N, pontos = -1, aux, c[] = {1, -1, 0, 0, 1, 1, -1, -1}, l[] = {0, 0, 1, -1, -1, 1, -1, 1}, tabuleiro[MAXN][MAXN];

void grid(int x, int y){

    for(int i = 0; i < 8; i++){
        int a = x + c[i], b = y + l[i];

        while( !(a < 0 or a >= N or b < 0 or b >= N or tabuleiro[a][b]) ){
            aux++;
            a += c[i];
            b += l[i];
        }
    }
}

int main(){_

    std::cin >> N;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) std::cin >> tabuleiro[i][j];

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(!tabuleiro[i][j]){
                grid(i, j);
                pontos = std::max(pontos, aux);
                aux = 0;
            }

    std::cout << pontos;
}
