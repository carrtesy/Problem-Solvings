#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

int N, cnt = 0;
vector< pair<int, int> > v; 

void hanoi(int n, int from, int via, int to){
	if(n == 1){
		v.push_back({from, to});
		cnt++;
		return;
	}
	hanoi(n-1, from, to, via);
	hanoi(1, from, via, to);
	hanoi(n-1, via, from, to);
}

int main(void){
	scanf("%d", &N);
	hanoi(N, 1, 2, 3);
	
	printf("%d\n", cnt);
	for(int i = 0; i < v.size(); i++){
		printf("%d %d\n", v[i].first, v[i].second);
	}
}
