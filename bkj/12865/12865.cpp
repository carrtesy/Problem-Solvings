#include <iostream>
#include <cstring>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, K;
	cin >> N >> K;
	int** dp = new int*[2];
	dp[0] = new int[K+1];
	dp[1] = new int[K+1];
	memset(dp[0], 0, sizeof(int)* (K+1));
	memset(dp[1], 0, sizeof(int)* (K+1));
	
	int k, k_1;
	for(int i = 0; i < N; i++){
		int W, V;
		cin >> W >> V;
		k = i % 2, k_1 = (i+1) % 2;
		
		for(int w_allowed = 0; w_allowed <= K; w_allowed++){
			if(W > w_allowed){
				dp[k][w_allowed] = dp[k_1][w_allowed];
			} else {
				dp[k][w_allowed] = max(dp[k_1][w_allowed], dp[k_1][w_allowed-W] + V);			
			}
		}
	}
	
	cout << dp[k][K] << '\n';
	
	delete[] dp;
}
