#include <bits/stdc++.h>
using namespace std;
int main(){

    int N, tam;

    cin >> N;

    vector<int> n1(N), n2;

    for(auto i = n1.begin(); i != n1.end(); i++){
        cin >> *i;
        n2.push_back(*i);
    }

    for(auto i = n1.begin(); i != n1.end(); i++){
        cout << *i << " " << *(i + 1) << endl;
        if(*i > *(i + 1) && i == n1.end() - 2){
            n2.push_back(*i);
            n2.push_back(*(i+1));
        }
        else if(*i > *(i + 1) && i != n1.end() - 1){
            n2.push_back(*i);
        }
    }
    sort(n2.begin(), n2.end());
    vector<int> n3(N);
    /*set_intersection(n1.begin(), n1.end(), n2.begin(), n2.end(), n3.begin());

    int tam1 = n1.size();
    int qtd = count(n3.begin(), n3.end(), 0);
    remove(n3.begin(), n3.end(), 0);
    n3.resize(n3.size() - qtd);
    n3.shrink_to_fit();

    cout << n3.size() << endl;
    /*for(auto i:n1){
        cout << i << " ";
    }
    cout << endl;
    for(auto i:n2){
        cout << i << " ";
    }
    cout << endl;*/
    for(auto i:n3){
        cout << i << " ";
    }

}
