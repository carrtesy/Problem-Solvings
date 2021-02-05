#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M;
	cin >> N >> M;
		
	// graph setting
	vector<int> *graph = new vector<int>[N+1];
	int* in_degree = new int[N+1];
	memset(in_degree, 0, sizeof(int)*(N+1));
	while(M--){
		int A, B;
		cin >> A >> B;
		graph[A].push_back(B);
		in_degree[B]++;					
	}
	
	// init
	queue<int> q;
	for(int st = 1; st <= N; st++){
		if(in_degree[st] == 0){
			q.push(st);
		}
	}
	
	// topological sort
	while(!q.empty()){
		int student = q.front();
		q.pop();
		printf("%d ", student);
		
		int gsize = graph[student].size();
		for(int i = 0; i < gsize; i++){
			int nxtst = graph[student][i];
			if(--in_degree[nxtst] == 0){
				q.push(nxtst);
			}
		}
	}
	
	delete[] graph;
	delete in_degree;
}
