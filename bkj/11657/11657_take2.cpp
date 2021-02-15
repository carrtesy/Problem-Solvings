#include <iostream>
#include <vector>
#include <cstring>
#define INF 500000011
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	
	// graph init
	int** graph = new int*[N+1];
	for(int r = 1; r <= N; r++){
		graph[r] = new int[N+1];
		for(int c = 1; c <= N; c++){
			graph[r][c] = INF;
		}
		graph[r][r] = 0;
	}
	
	for(int e = 0; e < M; e++){
		int A, B, C;
		cin >> A >> B >> C;
		graph[A][B] = min(graph[A][B], C);
	}
	
	// bellman-ford
	long long* dist = new long long[N+1];
	bool cycle_exists = false;
	for(int i = 0; i <= N; i++) dist[i] = INF;
	dist[1] = 0;
	for(int times = 1; times <= N; times++){
		for(int i = 1 ; i <= N; i++){
			if(dist[i] == INF) continue;
			for(int j = 1; j <= N; j++){
				int i_to_j = graph[i][j];	
				if(i == j || i_to_j == INF) continue;
				if(dist[j] > dist[i] + i_to_j){
					dist[j] = dist[i] + i_to_j;
					if (times == N) cycle_exists = true;
				}
			}
		}
	}
	
	// print out
	if(cycle_exists){
		printf("%d", -1);
	} else {
		for(int i = 2; i <= N; i++){
			int answer = (dist[i] == INF)? -1: dist[i];
			printf("%d\n", answer);
		}
	}
	
	delete[] graph;
	delete dist;
}
