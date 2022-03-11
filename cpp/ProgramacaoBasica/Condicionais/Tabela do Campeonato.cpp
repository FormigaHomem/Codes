#include <iostream>

using namespace std;

int main(){
    int J, P, V, E, D;

    cin >> J >> P >> V >> E >> D;

    switch(J){
        case -1:
            switch(P){
                case -1://Se não souber Jogos e Pontos.
                    P = (3 * V) + E;
                    J = V + E + D;
                    break;
                default:
                    switch(V){
                        case -1://Se não souber Jogos e Vitórias.
                            V  = (P - E) / 3;
                            J = V + E + D;
                            break;
                        default:
                            switch(E){
                                case -1://Se não souber Jogos e Empates.
                                    E = P - (V * 3);
                                    J = V + E + D;
                                    break;
                                default://Se só não souber os Jogos (Lembrando que não pode ter Jogos e Derrotas indefinidos, senão não tem como saber nenhum dos dois)
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
                        case -1://Se não souber Pontos e Vitórias.
                            V  = J - E - D;
                            P = (V * 3) + E;
                            break;
                        default:
                            switch(E){
                                case -1:// Se não souber Pontos e Empates.
                                    E = J - V - D;
                                    P = (V * 3) + E;
                                    break;
                                default:
                                    switch(D){
                                        case -1://Se não souber Pontos e Derrotas.
                                            D = J - V - E;
                                            P = (V * 3) + E;
                                            break;
                                        default://Se só não souber os Pontos.
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
                                case -1://Se não souber as Vitórias e os Empates.
                                    V = (P - J + D) / 2;
                                    E = P - (V * 3);
                                    break;
                                default:
                                    switch(D){
                                        case -1://Se não souber as Vitórias e Derrotas.
                                            V = (P - E) / 3;
                                            D = J - V - E;
                                            break;
                                        default://Se só não souber as Vitórias.
                                            V = J - E - D;
                                            break;
                                    }
                            }
                            break;
                        default:
                            switch(E){
                                case -1:
                                    switch(D){
                                        case -1://Se não souber os Empates e Derrotas.
                                            E = P - (V * 3);
                                            D = J - V - E;
                                            break;
                                        default://Se só não souber os Empates.
                                            E = J - V - D;
                                            break;
                                    }
                                default:
                                    switch(D){
                                        case -1://Se só não souber as Derrotas.
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
