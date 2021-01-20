#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int v, e, cnt, visit_order[10010], num = 1;
bool ans[10010];
vector<int> adj[10010];

int dfs(int parent, int cur, bool isRoot){
    int min_visit_order = 20000; // smallest among the node num that childs can meet
    int chlcnt = 0;
    visit_order[cur] = num; // cur's num
    num++;

    for(int i = 0; i < adj[cur].size(); i++){
        int nxt = adj[cur][i];
        if(nxt == parent) continue;
        if(visit_order[nxt]){
            min_visit_order = min(visit_order[nxt], min_visit_order);
        } else {
            //visit new
            int tmp = dfs(cur, nxt, false);
            min_visit_order = min(tmp, min_visit_order);
            if (isRoot == false && tmp >= visit_order[cur]){
                ans[cur] = true;
            }
            chlcnt++;
        }
    }

    if(isRoot){
        //child has more than two children
        if(chlcnt >= 2){
            ans[cur] = true;
        }
    }
    return min(min_visit_order, visit_order[cur]);
}

int main(void){
    scanf("%d%d", &v, &e);
    for(int i = 0; i < e; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= v; i++){
        if(visit_order[i] == 0){ // graphs are not all connected
            dfs(0, i, true);
        }
    }

    for(int i =1; i <= v; i++){
        if(ans[i]) cnt++;
    }
    printf("%d\n", cnt);
    for(int i = 1; i <= v; i++){
        if(ans[i]){
            printf("%d ", i);
        }
    }
}
