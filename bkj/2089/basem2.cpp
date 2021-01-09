#include <iostream>
#include <stack>

using namespace std;
int main(void){

  long long N;
  cin >> N;

  if(!N){
    cout << 0 << endl;
    return 0;
  }
  stack<bool> s;

  while(N){
    int r;
    r = N % (-2);
    N = N / (-2);
    if(r < 0){
      r -= -2;
      N += 1;
    }
    s.push((bool)r);
  }


  while(!s.empty()){
    cout << s.top();
    s.pop();
  }
  cout << endl;
}
