#include <iostream>

using namespace std;
long long getsumgcd(int * arr, int n){

  long long sum = 0;
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      int a, b;
      a = arr[i];
      b = arr[j];
      while(1){
        if(!b){
          break;
        }
        int tmp = a;
        a = b;
        b = tmp % b;
      }
      sum += a;
    }
  }

  return sum;
}

int main(void){
  int N;

  cin >> N;

  while(N--){
    int n;
    cin >> n;

    int *arr = new int[n];
    for(int i = 0 ; i < n ; i++){
      cin >> arr[i];
    }

    cout << getsumgcd(arr, n) << '\n';
    free(arr);
  }
}
