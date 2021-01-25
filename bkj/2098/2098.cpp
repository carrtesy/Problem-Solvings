#include <iostream>
#include <cstring>
#include <unistd.h>
#define INF -1 ^ (1<<31)
using namespace std;

int tsp(int **graph, int **dp, int N, int visited, int origin, int cur, int cost){
    int min_cost = INF;

    // check in
    visited |= (1 << cur);
    if(dp[cur][visited]){
        return dp[cur][visited];
    }
    // destination?
    if(visited == (1 << N) - 1){
        if(graph[cur][origin]){
            return cost + graph[cur][origin];
        } else {
            return INF;
        }
    }

    // iterate
    for(int city = 0; city < N; city++){
        // can we go?
        if(!(visited & (1<<(city))) && graph[cur][city]){
            min_cost = min(tsp(graph, dp, N, visited, origin, city, cost + graph[cur][city]), min_cost);
        }
    }
    cout << "memo: " << " cur: " << cur << " visited: " << visited << " cost: " << min_cost<< endl;
    dp[cur][visited] = min_cost;
    visited &= ~(1 << cur);
    return min_cost;
}

int main(void){
    int N;
    cin >> N;
    int** graph = new int*[N];
    int** dp = new int*[N];
    int visited = 0;
    for(int i = 0; i < N; i++) {
        graph[i] = new int[N];
        dp[i] = new int[1<<N];
        memset(dp[i], 0, sizeof(int) * (1<<N));
        for(int j = 0; j < N; j++){
            cin >> graph[i][j];
        }
    }
    cout << tsp(graph, dp, N, visited, 0, 0, 0) << endl;
}
