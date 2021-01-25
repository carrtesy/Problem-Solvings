#include <bits/stdc++.h>
using namespace std;
using namespace std;

void DFS(vector<int> *graph, int N, int cur, bool* visited){
    // check in
    visited[cur] = true;
    cout << cur << ' ';

    // destination? - no need
    // iterate
    int num_to_visit = graph[cur].size();
    for(int next = 0; next < num_to_visit; next++){
        // can we go?
        int nextnode = graph[cur][next];
        if(!visited[nextnode]){
            DFS(graph, N, nextnode, visited);
        }
    }
    // check out - no need
}

void BFS(vector<int> *graph, int N, int start, bool* visited){
    queue <int> q;
    memset(visited, 0, sizeof(bool)* (N+1));

    q.push(start);
    visited[start] = true;
    cout << start << ' ';

    while(!q.empty()){
        // pop
        int cur = q.front();
        q.pop();
        
        // destination? - no need
        // iterate
        int num_to_visit = graph[cur].size();
        for(int next = 0; next < num_to_visit; next++){
            //can we go?
            int nextnode = graph[cur][next];
            if(!visited[nextnode]){
                //check in & enqueue
                q.push(nextnode);
                visited[nextnode] = true;
                cout << nextnode << ' ';    
            }
        }
    } 
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // get inputs
    int N, M, V;
    cin >> N >> M >> V;

    vector<int> *graph = new vector<int> [N+1];
    bool* visited = new bool[N+1];
    memset(visited, 0, sizeof(bool) * (N+1));

    for(int i = 1; i <= M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int node = 1; node <= N; node++){
        sort(graph[node].begin(), graph[node].end()); 
    }

    // dfs, bfs
    DFS(graph, N, V, visited);
    cout << '\n';
    BFS(graph, N, V, visited);
    cout << '\n';
    
    // wrap up
    for(int i = 0; i <= N; i++) graph[i].clear();
    delete visited;
}
