#include <cstdio>
#include <cstring>

using namespace std;

struct coord{
	int r, c;
};

int depth;

int dfs(int** house, int N, int type, coord tail, coord head, int*** dp){
	int hr = head.r, hc = head.c, tr = tail.r, tc = tail.c;
	// destination?
	if(hr == N && hc == N){
		return 1;
	} else if(dp[hr][hc][type]){
		printf("dp!");
		return dp[hr][hc][type];
	}
	
	// check in
	// type 1 -> horizontal, 2 -> vertical, 3 -> slash
	house[tr][tc] = 1;
	house[hr][hc] = 1;
	if(type == 3){
		house[tr+1][tc] = 1;
		house[tr][tc+1] = 1;
	}
	
	// iterate
	int cases = 0;
	switch(type){
		case 1:{
			// right
			if(hc < N && !house[hr][hc+1]) {
				cases += dfs(house, N, 1, head, {hr, hc+1}, dp);
			}
			
			// right-down
			if(hr < N && hc < N && !house[hr][hc+1] && !house[hr+1][hc] && !house[hr+1][hc+1]){
				cases += dfs(house, N, 3, head, {hr+1, hc+1}, dp);
			}
			
			break;
		}
		case 2:{			
			// down
			if(hr < N && !house[hr+1][hc]) {
				cases += dfs(house, N, 2, head, {hr+1, hc}, dp);
			}
			
			// right-down
			if(hr < N && hc < N && !house[hr][hc+1] && !house[hr+1][hc] && !house[hr+1][hc+1]){
				cases += dfs(house, N, 3, head, {hr+1, hc+1}, dp);
			}
			
			break;
		}
		case 3:{
			// right
			if(hc < N && !house[hr][hc+1]) {
				cases += dfs(house, N, 1, head, {hr, hc+1}, dp);
			}
			
			// down
			if(hr < N && !house[hr+1][hc]) {
				cases += dfs(house, N, 2, head, {hr+1, hc}, dp);
			}
			
			// right-down
			if(hr < N && hc < N && !house[hr][hc+1] && !house[hr+1][hc] && !house[hr+1][hc+1]){
				cases += dfs(house, N, 3, head, {hr+1, hc+1}, dp);
			}
			
			break;
		}
	}

	// check out
	house[tr][tc] = 0;
	house[hr][hc] = 0;
	if(type == 3){
		house[tr+1][tc] = 0;
		house[tr][tc+1] = 0;
	}
	return dp[hr][hc][type] = cases;
}

int main(void){
	int N;
	scanf("%d", &N);
	
	int** house = new int*[N+1];
	int*** dp = new int**[N+1];
	for(int r = 1; r <= N; r++){
		house[r] = new int[N+1];
		dp[r] = new int*[N+1];
		
		for(int c = 1; c <= N; c++){
			scanf("%d", &house[r][c]);
			dp[r][c] = new int[4];
			memset(dp[r][c], 0, sizeof(int)*4);
		}
	}
	
	coord s1 = {1,1}, s2 = {1, 2};
	depth = 0;
	printf("%d\n", dfs(house, N, 1, s1, s2, dp));
}
