#include <iostream>
#include <vector>

using namespace std;

int main(){

    int N, M, I, R;

    cin >> N >> M >> I >> R;

    vector<bool> infecteds(N + 1, false);
    infecteds[I] = true;

    for(int i = 1; i <= M; i++){
        int A;
        cin >> A;
        vector<int> participants(A);

        for(auto j = participants.begin(); j != participants.end(); j++) cin >> *j;

        if(i >= R){
            bool someone_is_infected = false;
            for(int j : participants)
                if(infecteds[j]) someone_is_infected = true;
            if(someone_is_infected)
                for(int j : participants) infecteds[j] = true;
        }
    }

    int contaminateds = 0;

    for(bool i : infecteds)
        if(i) contaminateds++;

    cout << contaminateds;
}
