#include <iostream>

using namespace std;
int isPrime(int a){
  if(a == 1){
    return 0;
  }
  for(int i = 2; i*i <= a; i++){
    if(a % i == 0){
      return 0;
    }
  }
  return 1;
}

int main(void){
  int N;
  int cnt;
  cin >> N;

  cnt = 0;
  while(N--){
    int a;
    cin >> a;

    cnt += isPrime(a);

  }
  cout << cnt;
}
