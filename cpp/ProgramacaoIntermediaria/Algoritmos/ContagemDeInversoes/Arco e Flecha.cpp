#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long ull;

ull Tiros[100010], N;
long a, b;

ull merg(ull v[], int low, int high){
    ull k = low, i = low, mid = (low + high) / 2, j = mid + 1, temp[high + 10], inv = 0;

    while(i <= mid and j <= high){
        if(v[i] > v[j]) temp[k++] = v[i++];
        else{
            temp[k++] = v[j++];
            inv += mid - i + 1;
        }
    }

    while(i <= mid) temp[k++] = v[i++];
    while(j <= high) temp[k++] = v[j++];

    for(i = low; i <= high; i++) v[i] = temp[i];

    return inv;
}

ull merge_sort(ull v[], int low, int high){
    ull inv = 0, mid = (low + high) / 2;

    if(low < high) inv = merge_sort(v, low, mid) + merge_sort(v, mid + 1, high) + merg(v, low, high);
    
    return inv;
}

int main(){

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> a >> b;
        Tiros[i] = (a * a) + (b * b);
    }

    cout << merge_sort(Tiros, 0, N - 1) << endl;
}
