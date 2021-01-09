#include <iostream>
#include <cstring>
using namespace std;

int cntlogger(int N, int * counter, int cnt){

  if(!counter[N] || counter[N] > cnt){
    counter[N] = cnt;  
  } 

  if(N % 3 == 0){
    cntlogger(N/3, counter, cnt+1);
  }

  if(N % 2 == 0){
    cntlogger(N/2, counter, cnt+1);
  }

  if(N > 1){
    cntlogger(N-1, counter, cnt+1);   
  }
  
  if (N == 1) {
    return counter[1];
  }
}

int cnt_till_to1(int N){
  int * counter = new int[N+1];
  int cnt = 0;
  memset(counter, 0, sizeof(int) * (N+1));
  int ans;

  ans = cntlogger(N, counter, cnt);
  delete counter;
  return ans;
}

int main(void){
  int N;
  cin >> N;

  cout << cnt_till_to1(N) << endl;
}
