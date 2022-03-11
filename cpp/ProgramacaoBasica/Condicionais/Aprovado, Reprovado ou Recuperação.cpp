#include <iostream>

using namespace std;

int main(){

    int a, b, media;

    cin >> a >> b;

    a *= 2;
    b *= 3;

    cout << ( (a + b) / 5 >= 7? "Aprovado" : ( (a + b) / 5 >= 3? "Final" : "Reprovado") );

}
