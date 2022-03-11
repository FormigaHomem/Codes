#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int N, D;

    while(cin >> N >> D, D){
        string A;
        cin >> A;



        stack<char> maior(A);
        vector<int> integers;
        for(char i : A){
            int j = i - '0';
            integers.push_back(j);
        }
        for(int i = 1; i <= N - D; i++){
            vector<int>::iterator M = max_element(integers.begin(), integers.end() - (N - D) + i);//, it = integers.end() - (N - D) + i;
            //cout << D + i << " " << *it << endl;
            cout << *M;
            integers.erase(integers.begin(), M + 1);
        }
        cout << endl;
    }

}
