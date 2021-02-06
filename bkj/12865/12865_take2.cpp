#include <iostream>
#include <cstring>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	int* dp = new int[K+1];
	memset(dp, 0, sizeof(int) * (K+1));
	
	while(N--){	
		int W, V;
		cin >> W >> V;
		for(int i = K; i >= W; i--){
			dp[i] = max(dp[i], dp[i-W] + V);	
		}
	}
	
	cout << dp[K] << '\n';
	delete dp;
}


