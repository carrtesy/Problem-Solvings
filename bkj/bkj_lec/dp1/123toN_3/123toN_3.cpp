#include <iostream>
#define HASH 1000000009

using namespace std;

int main(void){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++){
    int n;
    cin >> n;

    // init
    long long *dp = new long long[n+1];
    
    // exceptional cases
    if(n == 1){
      cout << 1 << endl;
      continue;
    } else if ( n == 2) {
      cout << 2 << endl;
      continue;
    } else if (n == 3) {
      cout << 4 << endl;
      continue;
    }

    // trivial values
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
      
    // iterative
    for(int i = 4; i <= n; i++){
      dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % HASH;
    }

    cout << dp[n] << endl;
    delete dp;
  }
}

