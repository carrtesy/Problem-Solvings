#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    unordered_set<string> s;
    vector<string> dbjob;

    while(N--){
        string d;
        cin >> d;
        s.insert(d);
    }

    while(M--){
        string b;
        cin >> b;
        auto itr = s.find(b);
        if(itr != s.end()){
            dbjob.push_back(b);
        }
    }
    
    sort(dbjob.begin(), dbjob.end());
    
    int dbjs = dbjob.size();
    cout << dbjs << '\n';
    for(int i = 0; i < dbjs; i++){
        cout << dbjob[i] << '\n';
    }
}
