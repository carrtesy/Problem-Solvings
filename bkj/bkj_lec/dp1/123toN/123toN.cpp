#include <iostream>

using namespace std;

int logcase(int * memo, int n){
  if(memo[n]){
    return memo[n];
  } else {
    memo[n] = logcase(memo, n-1) 
            + logcase(memo, n-2) 
            + logcase(memo, n-3);
    return memo[n];
  }
}

int getcase(int n){
  int *memo = new int[n+1];
	int ans;
  memo[1] = 1;
  memo[2] = 2;
  memo[3] = 4;

  logcase(memo, n);

  ans = memo[n];

	delete memo;
	
	return ans;
}

int main(void){
  int T;
  cin >> T;


  while(T--){
    int n; 
    cin >> n;
    cout<< getcase(n) <<endl;
  }
}
