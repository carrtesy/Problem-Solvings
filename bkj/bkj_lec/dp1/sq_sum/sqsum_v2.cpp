#include <iostream>

using namespace std;
int main(void){
	// get input
  int N;
  cin >> N;
  int * dp = new int[N+1];

	// dp[N] = min(dp[N-d^2]) + 1
  dp[0] = 0;
  for(int i = 1; i <= N; i++){
    dp[i] = i;
    for(int j = 1; j * j <= i; j++){
      int tmp = dp[i - j*j] + 1;
      if(tmp < dp[i]){
        dp[i] = tmp;
      }
    }
  }
  cout << dp[N] << endl;
	
  delete dp;
}
