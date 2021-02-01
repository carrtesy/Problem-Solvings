#include <iostream>
#include <vector>
#include <queue>

#define INF 5000000 // # of edges at max: 300,000 and w is below 10

// to queue
struct nodepair{
    int nodenum;
    int mincost;
    bool operator<(nodepair other) const {
        return mincost > other.mincost;
    }
};


// graph info
struct info{
    int dest;
    int weight;
};

using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    int s;
    cin >> V >> E;
    cin >> s;

    // graph
    vector<info> *graph = new vector<info>[V+1];
    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }    

    // result
    int* result = new int[V+1];
    for(int i = 0; i <= V; i++) result[i] = INF;

    
    // dijkstra
    priority_queue<nodepair> pq;
    pq.push({s, 0});
    result[s] = 0;
    
    while(!pq.empty()){
        nodepair n = pq.top();
        pq.pop();
        int cur = n.nodenum;
        int curcost = n.mincost;

        for(int i = 0; i < graph[cur].size(); i++){
            int next = graph[cur][i].dest;
            // compare
            int candi = curcost + graph[cur][i].weight;
            if(candi < result[next]){
                result[next] = min(result[next], curcost + graph[cur][i].weight);
                // push to priority queue
                pq.push({next, result[next]});
            }   
        }
    }

    // outputs
    for(int i = 1; i <= V; i++){
        if(result[i] == INF){
            printf("INF\n");
        } else {
            printf("%d\n", result[i]);
        }
    }
    
    delete[] graph;
    delete result;
}
