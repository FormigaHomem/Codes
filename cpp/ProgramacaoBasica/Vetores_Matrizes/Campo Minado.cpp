#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, i;
    
    cin >> N;
    
    int C[N];
    
    int R[N];
    
    for(i = 0; i < N; i++){
        cin >> C[i];
        if(i == 1){
            switch(C[i - 1]){
                case 0:
                switch(C[i]){
                    case 0:
                    R[i - 1] = 0;
                    break;
                    case 1:
                    R[i - 1] = 1;
                    break;
                }
                break;
                case 1:
                switch(C[i]){
                    case 0:
                    R[i - 1] = 1;
                    break;
                    case 1:
                    R[i - 1] = 2;
                    break;
                }
                break;
            }
        }
        if(i > 1){
            switch(C[i - 2]){
                case 0:
                switch(C[i - 1]){
                    case 0:
                    switch(C[i]){
                        case 0:
                        R[i - 1] = 0;
                        break;
                        case 1:
                        R[i - 1] = 1;
                        break;
                    }
                    break;
                    case 1:
                    switch(C[i]){
                        case 0:
                        R[i - 1] = 1;
                        break;
                        case 1:
                        R[i - 1] = 2;
                        break;
                    }
                    break;
                }
                break;
                case 1:
                switch(C[i - 1]){
                    case 0:
                    switch(C[i]){
                        case 0:
                        R[i - 1] = 1;
                        break;
                        case 1:
                        R[i - 1] = 2;
                        break;
                    }
                    break;
                    case 1:
                    switch(C[i]){
                        case 0:
                        R[i - 1] = 2;
                        break;
                        case 1:
                        R[i - 1] = 3;
                    }
                    break;
                }
                break;
            }
        }
        if(i == (N - 1) ){
            switch(C[i - 1]){
                case 0:
                switch(C[i]){
                    case 0:
                    R[i] = 0;
                    break;
                    case 1:
                    R[i] = 1;
                    break;
                }
                break;
                case 1:
                switch(C[i]){
                    case 0:
                    R[i] = 1;
                    break;
                    case 1:
                    R[i] = 2;
                    break;
                }
                break;
            }
        }
    }
    
    for(i = 0; i < N; i++){
       cout << R[i] << endl;
    }
}

