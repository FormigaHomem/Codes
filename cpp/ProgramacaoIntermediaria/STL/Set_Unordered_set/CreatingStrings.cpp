#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 101010
#define INF 0x3f3f3f3f
#define LOG 20
#define lsb(x) x & (-x)
#define f first
#define s second
#define endl '\n'

using namespace std;

string seq;
set<char> s;
vector<int> cont(26);
vector<string> ans;
int strings;

int integer(char c){
    return (int) c - 'a';
}

int dp(string curr){
    if(curr.size() == seq.size() ){
        ans.push_back(curr);
        return 1;
    }

    int substrs = 0;
    for(int j = 0; j < s.size(); j++){
        auto i = next(s.begin(), j);

        if(cont[integer(*i)] > 1){
            cont[integer(*i)]--;
            substrs += dp(curr + *i);
            cont[integer(*i)]++;
        }

        else{
            auto temp = *i;

            s.erase(*i);
            substrs += dp(curr + temp);
            s.insert(temp);

            i = next(s.begin(), j);
        }
    }

    return substrs;
}

int main(){

    cin >> seq;

    for(auto i : seq){
        s.insert(i);
        cont[integer(i)]++;
    }

    for(int j = 0; j < s.size(); j++){
        auto i = next(s.begin(), j);
        string temp; temp += *i;

        if(cont[integer(*i)] > 1){
            cont[integer(*i)]--;
            strings += dp(temp);
            cont[integer(*i)]++;
        }

        else{
            s.erase(*i);
            strings += dp(temp);
            s.insert(temp.front() ); 
            i = next(s.begin(), j);  
        }
    }

    cout << strings << endl;
    for(auto i : ans) cout << i << endl;
}