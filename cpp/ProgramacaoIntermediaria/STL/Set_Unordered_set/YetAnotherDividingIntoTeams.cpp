#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e2 + 10

using namespace std;

long q, N, teams;

int main(){_

    cin >> q;

    while(q--){

        cin >> N;
        
        set<int> nums = {}; teams = 1;

        for(int i = 1; i <= N; i++){
            int a;
            cin >> a;
            nums.insert(a);
        }

        for(auto it = nums.begin(); it != nums.end(); it++){
            auto it2 = it, it3 = it, it1 = nums.end();
            if(it != nums.begin() ) it2--;
            if(it != --it1) it3++;

            if(*it3 - *it == 1 or *it - *it2 == 1){
                teams = 2;
                break;
            }
        }

        cout << teams << endl;
    }
}