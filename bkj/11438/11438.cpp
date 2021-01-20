#include <cstdio>
#include <vector>

using namespace std;

int n, m, depth[100010], an[100010][18];// 2^0, 2^n th ancestor;
vector <int> adj[100010];
bool visited[100010];

void dfs(int parent, int cur, int param_depth){
    if(visited[cur]) return;
    visited[cur] = true;
    depth[cur] = param_depth;
    an[cur][0] = parent;
    for(int i = 0; i < adj[cur].size(); i++){
        dfs(cur, adj[cur][i], param_depth + 1);
    }
}

int lca(int a, int b){
   // todo
   // same depth 
   if( depth[a] < depth[b]){
        // a is made deeper
        int tmp = a;
        a = b;
        b = tmp;
    }

    if(depth[a] != depth[b]){
        // a to be b 's depth
        int diff = depth[a] - depth[b];
        for(int i = 0, j =1; i <= 17; i++, j *= 2){
            if(diff & j){
                a = an[a][i];
            }
        }
    }

    // depth[a] == depth[b]
    if(a == b) return a;

    for(int i = 17; i >= 0; i--){
        if(an[a][i] != an[b][i]){
            a = an[a][i];
            b = an[b][i];
        }
    }

    // right below LCA
    return an[a][0];
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // 1, 2, 4 th ancestor
    // using dfs
    dfs(1, 1, 1);

    for(int i = 1; i <= 17; i++){ // 2^n th ancestor
        for(int j = 1; j <= n; j++){ // 1, 2, 3, .., n th node
            int tmp = an[j][i-1];
            an[j][i] = an[tmp][i-1]; // sparse table
        }
    }

    scanf("%d", &m);
    for(int i = 0; i < m i++){
        int a, b;
        scanf("%d%d", &a, &b);
        lca(a, b);
        
    }
}
