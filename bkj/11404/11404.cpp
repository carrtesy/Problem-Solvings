#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define INF 20000001

int n, m, dist[101][101]; // [i][j]
int adj[101][101];


void floyd(){
    for (int j = 1; j <= n; j++){ // middle
        for(int i = 1; i<= n; i++){ // start
            int path1 = dist[i][j];
            if(path1 == INF) continue;
            for(int k = 1; k <= n; k++){ // end
                int path2 = dist[j][k];
                int detour = path1+path2;
                if(path2 == INF) continue;
                if(detour < dist[i][k]){
                    dist[i][k] = detour;
                }
            }
        }
    }
}


int main(void){
    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i != j){
                dist[i][j] = INF;
            }
        }
    }

    for(int i = 0 ; i < m; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if(c < dist[a][b]){
            dist[a][b] = c; // only min
        }
    }

    floyd();

    for(int i = 1; i <= n; i++){
        for(int j =1; j <= n; j++){
            if(dist[i][j] == INF) printf("0 ");
            else printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
    
}
