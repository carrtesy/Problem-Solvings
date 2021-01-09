#include <iostream>

using namespace std;
int main(void){
  // init
  int N;
  cin >> N;
  int * arr = new int[N];
  int * sum = new int[N];
  int max;
 
  cin >> arr[0];
  sum[0] = max = arr[0];
  

  // logic
  // sum[N] = min{arr[N], sum[N-1] + arr[N]}
  for(int i = 1; i < N; i++){
    cin >> arr[i];
    int sub_sum = (0 > sum[i-1]) ? arr[i] : sum[i-1] + arr[i];
    sum[i] = sub_sum;
    if(sub_sum > max){
      max = sub_sum;
    }
  }

  cout << max << endl;

  delete arr;
  delete sum;
}
