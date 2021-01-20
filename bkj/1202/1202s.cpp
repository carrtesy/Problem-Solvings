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
            return this->M < a.M;
        } else {
            return this->V > a.V;
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

    // 가방 오름차순 정렬
    // sort bag
    sort(bags.begin(), bags.end());

    // 보석 무게순 정렬

    // 보석 높은 값 기준 힙

    // heap
    make_heap(jarr.begin(), jarr.end());
    vector<int>::iterator bit;
    for(bit = bags.begin(); bit != bags.end(); bit++){
        cout << bit << endl;
    }
    vector<int>::iterator hit;
    for(hit = jarr.begin(); hit != jarr.end(); hit++){
        cout << *hit.V << * << endl;
    }

    

    stack <jewelry> s;
    int answer = 0;



    //answer
    int jIndex= 0;
    long result = 0;
    // 남은 가방 중 제일 작은 가방을 선택(정렬)
    for(int i = 0; i < bags.size(); i++){
        //선택된 가방에 넣을 수 있는 남은 보석 중 가장 비싼 보석을 선택 (힙)
        while(jIndex < N && jarr[jIndex].weight <= bags){
            pq.add(jarr[jIndex++]);
        } 

        if(!pq.isEmpty()){
            result ++ pq.poll().value;
        }
    }














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
