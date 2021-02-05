#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	
	// directed graph
	vector<int> *graph = new vector<int>[N+1];
	int *in_degree = new int[N+1];
	memset(in_degree, 0, sizeof(int)*(N+1));
	for(int i = 0; i < M; i++){
		int A, B;
		cin >> A >> B;
		graph[A].push_back(B);
		in_degree[B]++;
	}
	
	// topological sort
	while(1){
		bool finished = true;
		for(int st = 1; st <= N; st++){
			// visited already
			if(in_degree[st] < 0){
				continue;
			}
			// new entry
			else if(in_degree[st] == 0){
				int connected = graph[st].size();
				for(int nxtst = 0; nxtst < connected; nxtst++){
					in_degree[graph[st][nxtst]]--;
				}
				in_degree[st]--;
				printf("%d ", st);
			}
			finished = false;
		}
		// nothing to visit, end
		if(finished) break;
	}
	
	for(int st = 1; st <= N; st++){
		if(in_degree[st] < 0){
			continue;
		}
		printf("%d ", st);
	}
	
	delete[] graph;
	delete in_degree;
}
