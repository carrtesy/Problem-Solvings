#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

void dfs(int node, int* depth, vector<int>* graph, int dpt){
	depth[node] = dpt;
	int gsize = graph[node].size();
	for(int i = 0; i < gsize; i++){
		dfs(graph[node][i], depth, graph, dpt+1);
	}
}

int LCA(int a, int b, int* parent, int* depth){
	// set b to be deeper
	if(depth[a] > depth[b]){
		int tmp;
		tmp = a;
		a = b;
		b = tmp;
	}
	
	// same depth
	while(depth[a] != depth[b]){
		b = parent[b];
	}
	
	// go upstairs
	while(a != b){
		a = parent[a];
		b = parent[b];
	}
	
	return a;
}

int main(void){
	int T; scanf("%d", &T);
	while(T--){
		int N; scanf("%d", &N);
		int* parent = new int[N+1]; memset(parent, 0, sizeof(int) * (N+1));
		int* depth = new int[N+1]; memset(depth, 0, sizeof(int) * (N+1));
		vector<int> * graph = new vector<int>[N+1];
		
		// node info
		for(int i = 1; i < N; i++){
			int a, b; scanf("%d %d", &a, &b);
			graph[a].push_back(b);
			parent[b] = a;
		}
		
		// root
		int root = 1;
		while(parent[root] != 0){
			root = parent[root];
		}
		
		// depth
		dfs(root, depth, graph, 1);
		
		// LCA
		int node1, node2; 
		scanf("%d %d", &node1, &node2);
		printf("%d\n", LCA(node1, node2, parent, depth));
		
		// wrap up
		delete[] graph;
		delete parent, depth;
	}
}
