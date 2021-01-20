#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int main(void){
    int N, M;
    cin >> N >> M;

    int* sum_degree = new int[N+1];
    int answer = 0;

    memset(sum_degree, 0, sizeof(int) * (N+1));    
    vector<int> graph[501];   

    for(int edge = 0; edge < M; edge++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);

        sum_degree[a] += 1;
        sum_degree[b] += 1;         
    }

    for(int node = 1; node <= N; node++){
        cout << sum_degree[node] << endl;
        if(sum_degree[node] == N-1){
            cout << "d" << endl;
            answer += 1;
        }
    }

    cout << N-1 << endl;   
    cout << answer << endl;
    
}
