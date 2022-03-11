#include <iostream>

int N, cont  = 0;

int func(int x){
    if(x == 1) return cont;
    cont++;
    return ( (x & 1)? func(3 * x + 1) : func(x / 2) );
}

int main(){

    std::cin >> N;

    std::cout << func(N);
}
