#include <iostream>

using namespace std;
int main(void){
  int max = -1;
  int idx = 0;
  for(int i = 1; i <= 9; i++){
    int candidate;
    cin >> candidate;
    if(candidate > max){
      max = candidate;
      idx = i;
    }
  }
  
  cout << max << endl;
  cout << idx << endl;
}
