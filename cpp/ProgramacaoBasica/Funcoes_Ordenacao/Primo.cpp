#include <iostream>

using namespace std;

bool eh_primo(int x){
    if(x == 1){
        return false;
    }
	for(int y = x - 1; y > 1; y--){
        if(x % y == 0 && y != 1){
            return false;
        }
	}
	return true;
}

int main(){
	int x;

	cin>>x;

	if(eh_primo(x)){
		cout << "S" << "\n";
	}else{
		cout << "N" << "\n";
	}
}
