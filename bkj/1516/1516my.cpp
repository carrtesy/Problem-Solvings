#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void){
    int n;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int* time = new int[n+1];
    vector <int> *graph = new vector<int>[n+1]; 
    queue <int> q;
    int* in_degree = new int[n+1];

    for(int building = 1; building <= n; building++){
        cin >> times[building];
        while(true){
            int other_b;  
            cin >> other_b;
            if(other_b == -1) break;
            graph[building].push_back(other_b);
            in_degree[building]++;
        }
    }

    // check in degree

    
    delete time;
    delete graph;
    delete in_degree;
}
