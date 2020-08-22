#include <iostream>
#define DIV 1000000000

using namespace std;
int main(void){
  int N, K;

  cin >> N;
  cin >> K;

  // dp[N][K] : make N out of K numbers.
  // setup 2D array

  long long ** dp = new long long * [N+1];
  for(int i = 0; i <= N; i++){
    dp[i] = new long long [K+1];
  } 


  // init
  for(int i = 0; i <= N; i++){
		dp[i][0] = 0;
    dp[i][1] = 1;
  }

  for(int k = 2; k <= K; k++){
    dp[0][k] = 1;
  }

  // dp[N][K] = sigma(dp[N-i][K-1])
  for(int k = 2; k <= K; k++){
    for(int n = 1; n <= N; n++){
      long long sum = 0;

      for(int i = 0; i <= n; i++){
        sum += dp[n-i][k-1];
      }
      dp[n][k] = sum % DIV;
    }
  }

  cout << dp[N][K] <<endl;


  // delete
  for(int i = 0; i <= N; i++){
    delete dp[i];
  } 

  delete dp;

  return 0;

}
