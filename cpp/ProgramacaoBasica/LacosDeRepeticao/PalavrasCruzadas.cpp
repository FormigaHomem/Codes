#include <iostream>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main(){_
    string horizontal, vertical;

    cin >> horizontal >> vertical;

    int fimh = horizontal.size() - 1, fimv = vertical.size() - 1, i, j;

    for(i = fimh; i >= 0; i--)
        for(j = fimv; j >= 0; j--)
            if(horizontal[i] == vertical[j]){
                cout << i + 1 << " " << j + 1 << endl;
                return 0;
            }

    cout << -1 << " " << -1 << endl;
}
