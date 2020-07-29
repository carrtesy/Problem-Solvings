#include <iostream>

using namespace std;

void logcases(int n, long long * memo){
  if(n == 1){
    memo[1] = 1;
    return;
  } else if ( n == 2 ) {
    memo[2] = 2;
    return;
  }
  
  long long a, b;

  if(!memo[n-1]){
    logcases(n-1, memo);
  }
  a = memo[n-1];

  if(!memo[n-2]){
    logcases(n-2, memo);
  }
  b = memo[n-2];

  memo[n] = (a + b) % 10007;
}

long long getcases(int n){
  long long *memo = new long long[n+1];

  logcases(n, memo);
  return memo[n];
}

int main(void){
  int n;
  cin >> n;

  long long ans;
  ans = getcases(n);
  cout << ans<< endl;
}
