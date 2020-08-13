#include <iostream>

using namespace std;

long long memo[4][100001];

long long getcases(int n, int last){
  if(n < 0) {
    return 0;
  }

  if(memo[last][n]){
    return memo[last][n];
  }

  long long cases = 0;
  if(n && last == 1){
    cases += getcases(n-2, 2);
    cases += getcases(n-3, 3);
  } else if(n && last == 2) {
    cases += getcases(n-1, 1);
    cases += getcases(n-3, 3);
  } else if(n && last == 3) {
    cases += getcases(n-1, 1);
    cases += getcases(n-2, 2);
  } else {
    cases += getcases(n-1, 1);
    cases += getcases(n-2, 2);
    cases += getcases(n-3, 3);
  }

  memo[last][n] = cases % 1000000009;
  return memo[last][n];
}

int main(void){
  int N;
  cin >> N;

  memo[1][0] = 1;
  memo[2][0] = 1;
  memo[3][0] = 1;

  while(N--){
    int n;
    cin >> n;

    cout << getcases(n, 0) << endl;
  }
}
