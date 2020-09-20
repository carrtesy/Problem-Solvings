#include <iostream>

using namespace std;
void track(int * arr, int * log, int idx){
  if(idx == -1){
    return;
  }

  track(arr, log, log[idx]);
  cout << arr[idx] << " ";
}

int main(void){
  // get input
  int N;
  cin >> N;

  int * arr = new int[N];
  int * ans = new int[N];
  int * log = new int[N];

  for(int i = 0; i < N; i++){
    cin >> arr[i]; 
  }
  
  // main logic
  int max = 1;
  int idx = -1;
  for(int i = 0; i < N; i++){
    for(int j = i; j >= 0; j--){
      if(j == i){
        ans[i] = 1;
        log[i] = -1;
        continue;
      }

      if(arr[j] < arr[i] && ans[j] + 1 > ans[i] ){
        ans[i] = ans[j] + 1;
        log[i] = j;
        idx = i;
        max = ans[i];
      }
    }

  }
  
  cout << max << endl;
//  track(arr, log, idx);
//  cout << endl;


  // wrap up
  delete arr;
  delete ans;
  delete log;

}
