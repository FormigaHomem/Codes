#include <iostream>
#include <algorithm>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 1e3 + 10

using namespace std;

int N, I, F, numbers[MAXN], possibilities, l, r;

int main(){

    cin >> N >> I >> F;

    for(int i = 0; i < N; i++) cin >> numbers[i];

    sort(numbers, numbers + N);

    l = 0; r = N - 1;

    while(l < r){
        int soma = numbers[l] + numbers[r];
        if(soma >= I and soma <= F and r != l){
            possibilities++;
            if(r - l > 1) r--;
            else{
                l++; r = N - 1;
            }
        }
        
        else if(soma < I){
            l++;
            r = N - 1;
        } 

        else r--;
    }

    cout << possibilities << endl;
}
