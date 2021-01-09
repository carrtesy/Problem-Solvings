#include <iostream>

using namespace std;
int main(void){
  int N;
  cin >> N;

  /*
    2D array memo[N+1][2]
    row : N+1
    col : 0, 1
    col index => Nth digit (0 or 1)
  */
  long long memo[N+1][2]; 

  memo[1][0] = 0;
  memo[1][1] = 1;

  for(int i = 2; i <= N; i++){
    long long prev_zero = memo[i-1][0];
    long long prev_one = memo[i-1][1];
    memo[i][0] = prev_zero + prev_one;
    memo[i][1] = prev_zero;
  }

  long long answer = memo[N][0] + memo[N][1];
  cout << answer << endl;
}
