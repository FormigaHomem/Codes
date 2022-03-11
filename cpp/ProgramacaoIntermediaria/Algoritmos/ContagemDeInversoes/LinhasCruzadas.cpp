#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 6e4 + 10
#define endl "\n"

using namespace std;

long N, V[MAXN];

long Merge(long v[], int ini, int fim){
    long mid = (ini + fim) / 2, k = ini, i = ini, j = mid + 1, temp[MAXN], inv = 0;

    while(i <= mid and j <= fim){

        if(v[i] < v[j]) temp[k++] = v[i++];
        else{
            temp[k++] = v[j++];
            inv += mid - i + 1;
        }
    }

    while(i <= mid) temp[k++] = v[i++];
    while(j <= fim) temp[k++] = v[j++];

    for(int i = ini; i <= fim; i++) v[i] = temp[i]; 

    return inv;
}


long long merge_sort(long v[], int ini, int fim){
    long inv = 0, mid = (ini + fim) / 2;

    if(ini < fim) inv = merge_sort(v, ini, mid) + merge_sort(v, mid + 1, fim) + Merge(v, ini, fim);
    
    return inv;
}


int main(){_

    cin >> N;

    for(int i = 1; i <= N; i++) cin >> V[i];
    
    cout << merge_sort(V, 1, N) << endl;
}