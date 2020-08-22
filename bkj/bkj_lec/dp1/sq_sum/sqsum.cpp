#include <iostream>

using namespace std;
int main(void){
  int N;
  cin >> N;

  int * sqcount = new int[N+1];

  // fill in square numbers
  for(int i = 1; i * i <= N; i++){
    sqcount[i* i] = 1;
    if(i*i == N){
      cout << 1 << endl;
      delete sqcount;
      return 0;
    }
  }

  for(int i = 1; i <= N; i++){
    if(sqcount[i]){
      continue;
    }
    
    int half = i / 2;
    int max = ~(1<<31);
    for(int j = 1; j <= half; j++){
      int a = j;
      int b = i - j;
      int candidate = sqcount[a] + sqcount[b];
      if(candidate < max){
        if(i == N){
          cout << "(a, b): " << "(" << a << "," << b << ")" << endl; 
        }
        max = candidate;
      }
    }

    sqcount[i] = max;
  }

  cout << sqcount[N] << endl;
  delete sqcount;
  return 0;
}
