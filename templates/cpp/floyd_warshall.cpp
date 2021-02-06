#include <iostream>
#define INF 111111111
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	
	// init
	int** dist = new int*[n+1];
	for(int i = 1; i <= n; i++){
		dist[i] = new int[n+1];
		for(int j = 1; j <= n; j++){
			dist[i][j] = INF;
		}
		dist[i][i] = 0;
	}
	
	while(m--){
		int a, b, c;
		cin >> a >> b >> c;
		if(dist[a][b] > c) dist[a][b] = c;
	}
	
	// floyd-Warshall
	for(int k = 1; k <= n; k++){
		// take node k considered as detour
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				int detour = dist[i][k] + dist[k][j];
				if(dist[i][j] > detour){
					// if detour is shorter, update
					dist[i][j] = detour;
				}
			}
		}
	}
	
	// print
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int i_to_j = (dist[i][j] == INF)? 0 : dist[i][j] ;
			printf("%d ", i_to_j);
		}
		printf("\n");
	}
	
	delete[] dist;
}
