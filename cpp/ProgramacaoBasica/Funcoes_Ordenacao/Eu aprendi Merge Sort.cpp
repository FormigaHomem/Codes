#include <bits/stdc++.h>

using namespace std;

void merg(long int *a, int b, long int c, int d){
    int i = b, j = d + 1, k = b, temp[c + 5];

    while(i <= d and j <= c){
        if(a[i] > a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }

    while(i <= d) temp[k++] = a[i++];
    while(j <= c) temp[k++] = a[j++];

    for(int i = b; i <= c; i++) a[i] = temp[i];
}

void merge_sort(long int A[], int low, long int high){

    if(low < high){
        int mid;
        mid = (low + high) / 2;

        merge_sort(A, low, mid);
        merge_sort(A, mid + 1, high);

        merg(A, low, high, mid);
    }
    return;
}

int main(){

    long int N, a;

    vector<long int> listaAux;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> a;
        listaAux.push_back(a);
    }

    long int lista[listaAux.size() + 10];

    copy(listaAux.begin(), listaAux.end(), lista);

    merge_sort(lista, 0, N - 1);

    for(int i = 0; i < N; i++) cout << lista[i] << " ";

}
