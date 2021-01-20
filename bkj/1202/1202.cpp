#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
class jewelry{
public:
    int M;
    int V;
    
    jewelry();
    jewelry(int m, int v){
        this->M = m;
        this->V = v;
    }

    bool operator<(jewelry &a){
        if(this->V != a.V){
            return this->M > a.M;
        } else {
            return this->V < a.V;
        }
    }
};

int main(void){
    int N, K;
    cin >> N >> K;
    
    vector <jewelry> jarr;
    vector <int> bags;

    for(int i = 0; i < N; i++) {
        int m, v;
        cin >> m >> v;
        jewelry j = jewelry(m, v);
        jarr.push_back(j);
    }
    for(int i = 0; i < K; i++){
        int limit;
        cin >> limit;
        bags.push_back(limit);
    }
    // sort bag
    sort(bags.begin(), bags.end());
    // heap
    make_heap(jarr.begin(), jarr.end());

    stack <jewelry> s;
    // small bag by sort
    // most expensive by heap
    // next bag

    int answer = 0;
    while(!jarr.empty() && !bags.empty()){
        jewelry j = jarr[0];
        pop_heap(jarr.begin(), jarr.end());
        
        vector<int>::iterator it;
        for(it = bags.begin(); it != bags.end(); it++){
            int limit_weight = *it;
            if(limit_weight < j.M){
                continue;
            } else {
                answer += j.V;
                bags.erase(it);
                break;
            }
        }
        
    }
    cout << answer << endl;
}
