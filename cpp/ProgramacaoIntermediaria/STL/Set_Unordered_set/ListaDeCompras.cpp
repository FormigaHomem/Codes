#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 101010
#define INF 0x3f3f3f3f
#define LOG 20
#define f first
#define s second
#define lsb(x) x & (-x)
#define endl '\n'

using namespace std;

int N;

int main(){
    fastio

    cin >> N;
    cin.ignore();

    while(N--){
        string s, temp;
        getline(cin, s);
        stringstream check(s);
        set<string> item;
        
        while(getline(check, temp, ' ') ) item.insert(temp);
        for(auto it = item.begin(); it != item.end(); it++){
            if(it != --item.end() ) cout << *it << " ";
            else cout << *it;
        }

        cout << endl;
    }
}