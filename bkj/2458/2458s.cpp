#include <cstdio>
#include <vector>
#include <cstring>


using namespace std;

int n, m, answer, visited_cnt, visited_rev_cnt;
bool visited[510], visited_rev[510];
vector<int> adj[510], rev[510];

int dfs(int cur){
    if(visited[cur]) return 0;

    // check in
    visited[cur] = true;

    // destination?

    // iterate
    //visited_cnt++;
    for(int i = 0; i < adj[cur].size(); i++){
        dfs(adj[cur][i]);
    } 
}

int dfs_rev(int cur){
    if(visited_rev[cur]) return 0;
}

int main(void){
    scanf("%d%d", &n, &m);

    // graph
    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);
        // a is less than b
        adj[a].push_back(b); // a --> b
        rev[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        // tall
        int visited_cnt = 0; // me + taller
        memset(visited, 0, sizeof(visited));
        dfs(i);

        // small
        int visited_rev_cnt = 0;    // me + smaller
        memset(visited_rev, 0, sizeof(visited_rev));
        dfs_rev(i);    

        if(visited_cnt + visited_rev_cnt == n + 1){
            answer++;
        }
    }
}
