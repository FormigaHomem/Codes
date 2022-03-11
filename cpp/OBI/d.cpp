#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define f first
#define s second
#define lsb(x) x & (-x)
#define INF 0x3f3f3f3f
#define LOG 20
#define MAXN 101010

using namespace std;

deque<char> a, b;
string A, B;

int main(){_

    cin >> A >> B;
    for(auto i : A) a.push_back(i);
    for(auto i : B) b.push_back(i);

    A = B = "";

    while(a.size() < b.size() ) a.push_front('0');
    while(b.size() < a.size() ) b.push_front('0');

    for(int i = 0; i < a.size(); i++){
        if(a[i] > b[i]) A += a[i];
        else if(b[i] > a[i]) B += b[i];
        else A += a[i], B += b[i];
    }

    if(A.empty() ) A = "-1";
    if(B.empty() ) B = "-1";

    if(stoll(A) > stoll(B) ) swap(A, B);

    if(count(A.begin(), A.end(), '0') == A.size() ) A = '0';
    if(count(B.begin(), B.end(), '0') == B.size() ) B = '0';

    cout << A << " " << B << endl; 
}