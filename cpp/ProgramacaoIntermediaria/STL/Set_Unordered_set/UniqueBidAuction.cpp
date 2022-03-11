#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 2e5 + 10
#define endl "\n"

using namespace std;

int t, n, a;

int main(){

    cin >> t;

    while(t--){

        cin >> n;

        set<int> nums, erased;
        int index[MAXN];
        

        for(int i = 1; i <= n; i++){
            cin >> a; 
            if(!nums.count(a) and !erased.count(a) ){
                nums.insert(a);
                index[a] = i;
            }
            else{
                nums.erase(a);
                erased.insert(a);
                index[a] = -1;
            }
        } 

        if(nums.size() ) cout << index[*nums.begin()] << endl;
        else cout << -1 << endl;
    }
}