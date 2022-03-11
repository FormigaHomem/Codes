#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

long N, D, C, possibilities;
vector<long> psa(1), psa_inv(1);

int main(){

    cin >> N >> D;

    for(int i = 1; i <= N; i++){
        cin >> C;
        psa.push_back(psa[i - 1] + C);
    }

    for(int i = 1; i <= N; i++) psa_inv.push_back(psa[N] - psa[i - 1]);

    for(int i = 1; i <= N; i++){
        int dif1 = (upper_bound(psa.begin() + i, psa.end(), D + psa[i - 1]) - psa.begin() - (lower_bound(psa.begin() + i, psa.end(), D + psa[i - 1]) - psa.begin() ) );
        int dif2 = (upper_bound(psa_inv.begin() + i, psa_inv.end(), D - psa[i], [] (int search, int comp) {return search > comp;} ) - psa_inv.begin() - (lower_bound(psa_inv.begin() + i, psa_inv.end(), D - psa[i], [] (int comp, int search) {return comp > search;} ) - psa_inv.begin() ) );
        possibilities += dif1 + dif2;
    }

    cout << possibilities << endl;
}