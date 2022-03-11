#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e3 + 10

using namespace std;

long N, Q, prefix[MAXN][MAXN];
char has_tree;

int main(){

    cin >> N >> Q;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++){
            cin >> has_tree;

            prefix[i][j] = (has_tree == '*'? 1 : 0) + prefix[i][j - 1] + prefix[i - 1][j] - prefix[i - 1][j - 1];
        }
    
    while(Q--){
        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        cout << prefix[x2][y2] - prefix[x2][y1 - 1] - prefix[x1 - 1][y2] + prefix[x1 - 1][y1 - 1] << endl;
    }

}