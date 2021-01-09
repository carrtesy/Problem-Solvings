#include <iostream>
#define HASH 9901

using namespace std;
int main(void){
  int N;
  int answer;
  cin >> N;

  // init
  int **dp = new int* [N+1];
  for(int i = 1; i <= N; i++){
    dp[i] = new int[3];
  }

  dp[1][0] = 1;
  dp[1][1] = 1;
  dp[1][2] = 1;

  // dp

  // 0 : nothing
  // 1 : left
  // 2 : right
  for(int i = 2; i <= N; i++){
    dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % HASH;
    dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % HASH;
    dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % HASH; 
  }

  // result
  answer = dp[N][0] + dp[N][1] + dp[N][2];
  cout << answer << endl;

  // delete
  for(int i = 1; i <= N; i++){
    delete dp[i];
  }
  delete dp;
}
