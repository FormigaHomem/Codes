#include <bits/stdc++.h>
using namespace std;
int main(){
    int A, B, C, H, L;
    
    A>=1 && A<=100;
    
    B>=1 && B<=100;
    
    C>=1 && C<=100;
     
    H>=1 && H<=100;
    
    cin >> A;
    cin >> B;
    cin >> C;
    cin >> H;
    cin >> L;
    
    
    if( (H >= A) && (L >= B) || (H >= A) && (L >= C) || (H >= B) && (L >= A) || (H >= B) && (L >= C) || (H >= C) && (L >= A) || (H >= C) && (L >= B) ){
        cout << "S";
    }
    else{
        cout << "N";
    }
    
}
