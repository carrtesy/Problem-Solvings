#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

struct jewelry{
	int w, v;
};

bool wcmp(jewelry a, jewelry b){
	return a.w < b.w;
}

struct cmp{
	bool operator()(jewelry a, jewelry b){
		return a.v < b.v;
	}	
};

using namespace std;
int main(void){
	int N, K;
	scanf("%d %d", &N, &K);
	
	priority_queue<jewelry, vector<jewelry>, cmp> pq;
	vector<jewelry> jewels;
	vector<int> bags;
	for(int j = 0; j < N; j++){
		int m, v;
		scanf("%d %d", &m, &v);
		jewels.push_back({m, v});
	}
	
	for(int b = 0; b < K; b++){
		int bag;
		scanf("%d", &bag);
		bags.push_back(bag);
	}
	
	sort(jewels.begin(), jewels.end(), wcmp);
	sort(bags.begin(), bags.end());
	
	long long answer = 0;
	int ptr = 0;
	for(int b = 0; b < K; b++){
		int capacity = bags[b];
		while(ptr < N && jewels[ptr].w <= capacity){
			pq.push(jewels[ptr++]);
		}
		if(!pq.empty()){
			answer += pq.top().v;
			pq.pop();
		}
	}
	printf("%lld\n", answer);
}
