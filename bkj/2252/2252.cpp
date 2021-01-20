#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

int n, m, indegree[32010];
vector<int> adj[32010];
queue<int> q;

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);

        // a->b
        adj[a].push_back(b);
        indegree[b]++;
    }

    // indegree is 0
    // collect
    for(int i = 1; i <= n; i++){
        // into queue
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    // print collected
    // delete line links
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        cout << cur << ' ';

        for(int i = 0; i < adj[cur].size(); i++){
            int nxt = adj[cur][i];
            indegree[nxt]--;
            if(indegree[nxt] == 0){
                q.push(nxt);    
            }
        }
    }
}



