#include <iostream>

using namespace std;

int main(void){
  int N;
  cin >> N;

  int cnt = 0;
  for(int i = 1; i <= N; i++){
    int tmp = i;
    while(tmp % 5 == 0){
      cnt++;
      tmp = tmp / 5;
    }
  }

  cout << cnt << endl;
}
