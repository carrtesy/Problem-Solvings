#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main(void){
  string N;
  cin >> N;
  stack <char> s;
  int strlen = N.length();

  // repeat 3 digits
  for(int i = strlen-1; i >= 2; i -= 3){
    char num;
    int first, second, third;
    first = N[i-2] - '0';
    second = N[i-1] - '0';
    third = N[i] - '0';
    
    num = ((first << 2) + (second << 1) + (third)) + '0';
    s.push(num);
  }
  
  // leftovers
  int leftover = strlen % 3;
  if(leftover){
    int sum = 0;
    for(int i = leftover-1; i >= 0; i--){
      sum += (N[i] -'0')  << (leftover-i-1);
    }
    s.push(sum+'0');
  }

  // printout
  while(!s.empty()){
    cout << s.top();
    s.pop();
  }
  cout << endl;
}
