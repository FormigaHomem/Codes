#include <bits/stdc++.h>
using namespace std;
int main(){

    int a, b, c;

    cin >> a >> b >> c;

    if(a < b && b < c && a < c){
        cout << a << "\n" << b << "\n" << c;
    }
    else if(a < b && c < b && a < c){
        cout << a << "\n" << c << "\n" << b;
    }
    else if(b < a && a < c && b < c){
        cout << b << "\n" << a << "\n" << c;
    }
    else if(b < a && c < a && b < c){
        cout << b << "\n" << c << "\n" << a;
    }
    else if(c < a && a < b && c < a){
        cout << c << "\n" << a << "\n" << b;
    }
    else if(c < b && b < a && c < a){
        cout << c << "\n" << b << "\n" << a;
    }
    else if(a == b && b < c){
        cout << a << "\n" << b << "\n" << c;
    }
    else if(b == c && c < a){
        cout << b << "\n" << c << "\n" << a;
    }
    else if(a == c && c < b){
        cout << a << "\n" << c << "\n" << b;
    }
    else if(a == b && b > c){
        cout << c << "\n" << b << "\n" << a;
    }
    else if(b == c && c > a){
        cout << a << "\n" << c << "\n" << b;
    }
    else if(a == c && c > b){
        cout << b << "\n" << c << "\n" << a;
    }
    else if(a == b && b == c){
        cout << a << "\n" << b << "\n" << c;
    }

}
