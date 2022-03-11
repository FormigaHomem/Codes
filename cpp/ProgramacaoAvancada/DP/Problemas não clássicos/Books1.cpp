#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (int) 5e2 + 10
#define MAXP (long) 1e7 + 10

using namespace std;

long T, N, K, book[MAXN], maxsum, prefix_sum[MAXN];
vector<int> idxs;

long scribers(long sum){
    // dp q eu nn sei ainda aq :(
}

long long bb(){
    long long ini = 0, end = maxsum, mid;
    
    while(ini <= end){
        mid = (ini + end) / 2;
        long sz = scribers(mid);

        if(sz == K) return mid;
        
        if(sz < K) end = mid - 1;
        else ini = mid + 1;
    }

    return mid;
}

int main(){

    cin >> T;

    while(T--){
        cin >> N >> K;

        for(int i = 1; i <= N; i++){
            cin >> book[i];
            maxsum += book[i];
            prefix_sum[i] = prefix_sum[i - 1] + book[i];
        }

        cout << endl << bb() << endl;
        for(auto i : idxs) cout << i << " ";
        cout << endl;

        int idx = 0;
        for(int i = 1; i <= N; i++){
            cout << book[i] << " ";
            if(idxs[idx] == i and i < N){
                cout << "/ ";
                idx++;
            }
        }

        idxs.clear();
        maxsum = 0;
        cout << endl;
    }
}