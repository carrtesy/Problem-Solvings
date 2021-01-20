#include <cstdio>
#include <vector>

using namespace std;

#define INF 10000000

struct Info{
    int b, c;
    Info(int bb, int cc){
        b = bb;
        c = cc;
    }
};

int n, m, dist[510];
vector<Info> adj[510];
bool has_minus_cycle = false;

void bell(){
    // init
    dist[1] = 0;
    for(int i = 0; i < n-1; i++){ // maximum visitable: n-1
        for(int j = 1; j <= 1; j++){
            for(int k = 0; k < adj[j].size(); k++){
                Info nxt = adj[j][k]; // nxt.b : near j / nxt.c cost
                if(dist[j] + nxt.c < dist[nxt.b]){
                    //here
                }
            }
        }
    }
    
    // n-1 times > already arrived
    // 
    for(int j = 1; j <= 1; j++){
        for(int k = 0; k < adj[j].size(); k++){
            Info nxt = adj[j][k]; // nxt.b : near j / nxt.c cost
            if(dist[j] + nxt.c < dist[nxt.b]){
                dist[nxt.b] = dist[j] + nxt.c; // j -> nxt less cost.
            }
        }
    }

}

int main(){
    scanf("%d%d", &n, &m);
    
    for(int i = 0; i < m; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back(Info(b,c));
    }

    for(int i = 1; i <= n; i++){
        dist[i] = INF;
    }

    bell();
    
    if(has_minus_cycle){
        printf("-1");
    } else {
        for(int i = 2; i <= n; i++){
            if(dist[i] == INF) printf("-1\n");
            else printf("%d\n", dist[i]);
        }
    }
}

