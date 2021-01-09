#include <iostream>

using namespace std;
int main(void){
  int N;
  cin >> N;
  int *p = new int[N+1];

  p[0] = -1;
  cin >> p[1];
  for(int i = 2; i <= N; i++){
    int pi; 
    cin >> pi;
    int sum = ~(1<<31); // INT MAX
    for(int j = 1; j < i; j++){
      int sum_candidate = p[j] + p[i-j];
      if(sum_candidate < sum){
        sum = sum_candidate;
      }
    }

    p[i] = min(sum, pi);
  }

  cout << p[N] << endl;
}
