#include <iostream>

using namespace std;

int getCount(int * arr, int n){
  // check if data is in already

  if(arr[n]){
    return arr[n];
  } else if(n == 1) {
    return 0;
  }
  
  // a: n / 3
  // b: n / 2
  // c: n - 1

  
  if(n % 3 == 0 && n % 2 == 0){
    int a = getCount(arr, n/3);
    int b = getCount(arr, n/2);
    int c = getCount(arr, n-1);
    arr[n] = min(min(a, b), c) + 1;
  } else if(n % 3 == 0){
    int a = getCount(arr, n/3);
    int c = getCount(arr, n-1);
    arr[n] = min(a,c)+1;
  } else if(n % 2 == 0){
    int b = getCount(arr, n/2);
    int c = getCount(arr, n-1);
    arr[n] = min(b,c)+1;
  } else {
    int c = getCount(arr, n-1);
    arr[n] = c + 1;
  }

  return arr[n];
}

int main(void){
  int N; 

  cin >> N;
  
  int * memo = new int[N+1];

  memo[0] = 0;
  memo[1] = 0;

  if(N == 1){
    cout << 0 << endl;
    return 0;
  }
  
  cout << getCount(memo, N) << endl;
  return 0;
}
