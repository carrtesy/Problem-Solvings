#include <iostream>
#include <unistd.h>

using namespace std;

int memo[1000001];

int getCount(int n){
 // sleep(1);
  //cout << n << endl;
  // check if data is in already

  if(n == 1) return 0;
  if(memo[n] > 0) return memo[n];

  memo[n] = getCount(n-1) + 1;
  if(n % 2 == 0) {
    int tmp = getCount(n/2) + 1;
    if(memo[n] > tmp) memo[n] = tmp;
  }

  if(n % 3 == 0) {
    int tmp = getCount(n/3) + 1;
    if(memo[n] > tmp) memo[n] = tmp;
  }

  return memo[n];
  /*
  if(arr[n]){
    cout << "in memo" << endl;
    return arr[n];
  } else if(n == 1) {
    return 0;
  }
  
  // a: n / 3
  // b: n / 2
  // c: n - 1

  
  if(n % 3 == 0 && n % 2 == 0){
    cout << "divisible 3, 2" <<endl;
    int a = getCount(arr, n/3);
    int b = getCount(arr, n/2);
    int c = getCount(arr, n-1);
    arr[n] = min(min(a, b), c) + 1;
  } else if(n % 3 == 0){
    cout << "divisible 3" <<endl;
    int a = getCount(arr, n/3);
    int c = getCount(arr, n-1);
    arr[n] = min(a,c)+1;
  } else if(n % 2 == 0){
    cout << "divisible 2" <<endl;
    int b = getCount(arr, n/2);
    int c = getCount(arr, n-1);
    arr[n] = min(b,c)+1;
  } else {
    cout << "divisible nothing" <<endl;
    int c = getCount(arr, n-1);
    arr[n] = c + 1;
  }

  cout << n << ":" << arr[n] << endl;
  return arr[n];
  */
}

int main(void){
  int N; 

  cin >> N;
  cout << N << endl;
  sleep(1);

  
  //int * memo = new int[N+1];

  memo[0] = 0;
  memo[1] = 0;

  if(N == 1){
    cout << 0 << endl;
    return 0;
  }
  
  cout << "original" << endl;
  sleep(1);
  cout << getCount(N) << endl;
  return 0;
}
