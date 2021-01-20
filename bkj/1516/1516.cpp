#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n, build_time[510], answer[510], indegree[510], before_max[510];
vector<int> adj[510];
queue<int> q;


int main(void){
    scanf("%d", &n);
    for(int i = 1 ; i <= n; i++){
        scanf("%d", &build_time[i]);

        while(true){
            int a;
            scanf("%d", &a);
            if(a == -1) break;

            adj[a].push_back(i);
            indegree[i]++;
        }
    }

    // topological sort
    // indegree is 0
    for (int i = 1; i <= n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        // processing cur
        answer[cur] = before_max[cur] + build_time[cur];
        // next building -> edge-1, before_max value
        for(int i = 0; i < adj[cur].size(); i++){
            int nxt = adj[cur][i];
            indegree[nxt]--;
            if (before_max[nxt] < answer[cur]){
                before_max[nxt] = answer[cur];
            } 

            if(indegree[nxt] == 0){
                q.push(nxt);
            }
        }
    }
    
    // print answer
    for(int i = 1; i <= n; i++){
        printf("%d\n", answer[i]);
    }
}
