#include <iostream>

using namespace std;

int main(){
    int J, P, V, E, D;

    cin >> J >> P >> V >> E >> D;

    switch(J){
        case -1:
            switch(P){
                case -1://Se n�o souber Jogos e Pontos.
                    P = (3 * V) + E;
                    J = V + E + D;
                    break;
                default:
                    switch(V){
                        case -1://Se n�o souber Jogos e Vit�rias.
                            V  = (P - E) / 3;
                            J = V + E + D;
                            break;
                        default:
                            switch(E){
                                case -1://Se n�o souber Jogos e Empates.
                                    E = P - (V * 3);
                                    J = V + E + D;
                                    break;
                                default://Se s� n�o souber os Jogos (Lembrando que n�o pode ter Jogos e Derrotas indefinidos, sen�o n�o tem como saber nenhum dos dois)
                                    J = V + E + D;
                                    break;
                            }
                            break;
                    }
                    break;
            }
            break;
        default:
            switch(P){
                case -1:
                    switch(V){
                        case -1://Se n�o souber Pontos e Vit�rias.
                            V  = J - E - D;
                            P = (V * 3) + E;
                            break;
                        default:
                            switch(E){
                                case -1:// Se n�o souber Pontos e Empates.
                                    E = J - V - D;
                                    P = (V * 3) + E;
                                    break;
                                default:
                                    switch(D){
                                        case -1://Se n�o souber Pontos e Derrotas.
                                            D = J - V - E;
                                            P = (V * 3) + E;
                                            break;
                                        default://Se s� n�o souber os Pontos.
                                            P = (V * 3) + E;
                                            break;
                                    }
                                    break;
                            }
                            break;
                    }
                    break;
                default:
                    switch(V){
                        case -1:
                            switch(E){
                                case -1://Se n�o souber as Vit�rias e os Empates.
                                    V = (P - J + D) / 2;
                                    E = P - (V * 3);
                                    break;
                                default:
                                    switch(D){
                                        case -1://Se n�o souber as Vit�rias e Derrotas.
                                            V = (P - E) / 3;
                                            D = J - V - E;
                                            break;
                                        default://Se s� n�o souber as Vit�rias.
                                            V = J - E - D;
                                            break;
                                    }
                            }
                            break;
                        default:
                            switch(E){
                                case -1:
                                    switch(D){
                                        case -1://Se n�o souber os Empates e Derrotas.
                                            E = P - (V * 3);
                                            D = J - V - E;
                                            break;
                                        default://Se s� n�o souber os Empates.
                                            E = J - V - D;
                                            break;
                                    }
                                default:
                                    switch(D){
                                        case -1://Se s� n�o souber as Derrotas.
                                            D = J - V - E;
                                            break;
                                    }
                                    break;
                            }
                            break;

                    }
                    break;

            }
            break;

    }

    cout << J << " " << P << " " << V << " " << E << " " << D;

}
