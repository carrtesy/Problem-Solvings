#include <cstdio>
#include <vector>
#include <queue>
#define INF 200001

using namespace std;

struct Info{
    int b, c;
    Info (int bb, int cc){
        b = bb; 
        c = cc;
    }
};

struct Dijk_Info{
    int node_num, node_dist;
    Dijk_Info(int nn, int nd){
        node_num = nn;
        node_dist = nd;
    }
};

struct comp{
    bool operator()(Dijk_Info a, Dijk_Info b){
        return a.node_dist > b.node_dist;
    }
};

int v, e, dist[20010], start_point;
vector<Info> adj[20010];

void dijk(){
    priority_queue<Dijk_Info, vector<Dijk_Info>, comp> pq;
    // starting point distance setting
    // push to pq

    dist[start_point] = 0;
    pq.push(Dijk_Info(start_point, 0));

    while(!pq.empty()){
        Dijk_Info cur = pq.top();
        pq.pop();
        // additional distance is bigger, just skip.
        if(dist[cur.node_num] < cur.node_dist) continue;
        // neighborhood of cur
        for(int i = 0; i < adj[cur.node_num].size(); i++){
            Info nxt = adj[cur.node_num][i];
            int tmp = cur.node_dist + nxt.c; // cost of cur to nxt
            if(tmp < dist[nxt.b]){
                dist[nxt.b] = tmp;
                pq.push(Dijk_Info(nxt.b, tmp));
            }
        }
    }
}


int main(){
    scanf("%d%d", &v, &e);
    scanf("%d", &start_point);
    for(int i = 0; i < e; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back(Info(b, c)); // a to b, weight c
    }

    for(int i = 1; i <= v; i++) dist[i] = INF;

    dijk();

    for(int i = 1; i <= v; i++){
        if(dist[i] == INF){
            printf("INF\n");
        } else{
            printf("%d\n", dist[i]);
        }
    }
}
