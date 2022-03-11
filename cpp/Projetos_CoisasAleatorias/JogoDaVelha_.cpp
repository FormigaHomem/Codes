#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

string win(string v[3][3]){
    if( (v[0][0] == v[1][1] and v[1][1] == v[2][2] and v[0][0] == v[2][2] and v[0][0] != " ") or (v[0][2] == v[1][1] and v[1][1] == v[2][0] and v[0][2] == v[2][0] and v[0][2] != " ") ) return v[0][0];
    for(int i = 0; i < 3; i++){
        if(v[i][0] == v[i][1] and v[i][1] == v[i][2] and v[i][0]  == v[i][2] and v[i][0] != " ") return v[i][0];
        if(v[0][i] == v[1][i] and v[1][i] == v[2][i] and v[0][i]  == v[2][i] and v[0][i] != " ") return v[0][i];
    }

    return " ";
}

int main(){

    string player1, player2, matrix[3][3] = { {" ", " ", " "}, {" ", " ", " "}, {" ", " ", " "} };
    int round = 1;

    retry:
    cout << "Player 1, digite quem voce sera, O ou X\n";
    cin >> player1;
    if(player1 == "O"){
        cout << "Player2, voce e o X!\n";
        player2 = "X";
    }
    else if(player1 == "X"){
        cout << "Player2, voce e o O!\n"; 
        player2 = "O";
    }
    else{
        system("cls");
        cout << "Voce digitou uma letra invalida! Digite X ou O.\n";
        goto retry;
    }

    while(win(matrix) == " " and round <= 9){
        cout << "Player1: " << player1 << " \t Player2: " << player2 << endl;  
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(j < 2) cout << matrix[i][j] << " | ";
                else cout << matrix[i][j];
            }
            if(i < 2) cout << "\n__________\n\n";
            else cout << "\n__________\n";
        }
                
        int linha, coluna;
        
        cout << "Em qual linha e coluna deseja posicionar sua jogada? Digite um numero entre 1 e 3 para a linha e para a coluna!\n";
        retry2:
        cin >> linha >> coluna;
        if(linha < 1 or linha > 3 or coluna < 1 or coluna > 3 or matrix[linha - 1][coluna - 1] != " "){
            system("cls");
            cout << "Voce digitou algum numero invalido! Digite um numero entre 1 e 3 para a linha e para a coluna e de forma que tal celula esteja vazia.\n";
            goto retry2;
        }

        if(round % 2 == 0) matrix[linha - 1][coluna - 1] = player2;
        else matrix[linha - 1][coluna - 1] = player1;
        ++round;
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(j < 2) cout << matrix[i][j] << " | ";
            else cout << matrix[i][j];
        }
        if(i < 2) cout << "\n__________\n\n";
        else cout << "\n__________\n";
    }

    if(win(matrix) == player1) cout << "Parabens Player 1, voce ganhou!\n";
    else if(win(matrix) == player2) cout << "Parabens Player 2, voce ganhou!\n";
    else cout << "Deu velha! Parabens Player 1 e Player 2, jogaram bem!";
}