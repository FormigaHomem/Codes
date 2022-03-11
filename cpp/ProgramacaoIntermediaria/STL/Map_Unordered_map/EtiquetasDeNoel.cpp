#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 101010
#define INF 0x3f3f3f3f
#define LOG 20
#define f first
#define s second
#define lsb(x) x & (-x)
#define endl "\n"

using namespace std;

long N, M;
map<string, string> translation;

int main(){
    //fastio
    
    cin >> N;
    cin.ignore();

    while(N--){
        string idiom, translate;

        getline(cin, idiom);
        getline(cin, translate);

        translation[idiom] = translate;
    }

    cin >> M;
    cin.ignore();

    while(M--){
        string name, idiom;
        getline(cin, name);
        getline(cin, idiom);

        cout << name << endl << translation[idiom] << "\n\n";
    }
}