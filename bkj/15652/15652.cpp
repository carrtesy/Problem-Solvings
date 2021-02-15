#include <cstdio>
#include <vector>
using namespace std;
void dfs(int N, int M, vector<int> v){
	int vsize = v.size();
	if(vsize == M){
		for(int i = 0; i < vsize; i++){
			printf("%d ", v[i]);
		}
		printf("\n");
		return;
	}
	
	int start = (vsize == 0)? 1: v[vsize-1];
	for(int i = start; i <= N; i++){
		v.push_back(i);
		dfs(N, M, v);
		v.pop_back();
	}
}

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	vector<int> v;
	dfs(N, M, v);
}
