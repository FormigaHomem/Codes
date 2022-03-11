#include <iostream>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main(){_

    int N, num;
    char C;

    cin >> N >> C;

    for(int i = 0; i < N; i++){
        cin >> num;
        switch(C){
            case 'A':
                switch(num){
                    case 1:
                        C = 'B';
                        break;
                    case 3:
                        C = 'C';
                        break;
                }
                break;
            case 'B':
                switch(num){
                    case 1:
                        C = 'A';
                        break;
                    case 2:
                        C = 'C';
                        break;
                }
                break;
            case 'C':
                switch(num){
                    case 2:
                        C = 'B';
                        break;
                    case 3:
                        C = 'A';
                        break;
                }
                break;
        }
    }

    cout << C;

}
