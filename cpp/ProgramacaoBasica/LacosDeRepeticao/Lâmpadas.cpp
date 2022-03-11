#include <bits/stdc++.h>
using namespace std;
int main(){
    int I1, I2, FA, FB, I, N;

    FA = 0;
    FB = 0;

    N >= 1 and N <= 10000;

    cin >> N;

    for(int contador = 0; contador < N; contador++){
        cin >> I;
        switch(I){
            case 1:
            switch(FA){
                case 0:
                FA = 1;
                break;
                case 1:
                FA = 0;
                break;
            }continue;
            case 2:
            switch(FA){
                case 1:
                switch(FB){
                    case 1:
                    FA = 0;
                    FB = 0;
                    break;
                    case 0:
                    FA = 0;
                    FB = 1;
                    break;
                }continue;
                case 0:
                switch(FB){
                    case 1:
                    FA = 1;
                    FB = 0;
                    break;
                    case 0:
                    FA = 1;
                    FB = 1;
                }
            }
        }
    }

    cout << FA << endl;
    cout << FB << endl;
}