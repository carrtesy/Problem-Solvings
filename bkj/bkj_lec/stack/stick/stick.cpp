#include <iostream>
#include <string>

using namespace std;
int main(void){
  int sticks, answer;
  int strlen;
  string str;
  cin >> str;
  
  strlen = str.length();
  sticks = 0;
  answer = 0;

  int idx = 0;

  while(1){

    if(str[idx] == '(' && str[idx+1] == ')'){
      answer += sticks;
      idx += 2;
      continue;
    }

    if(str[idx] == '('){
      sticks++;
      idx++;
    } else if(str[idx] == ')'){
      answer++;
      sticks--;
      idx++;
    }

    if(idx >= strlen){
      break;
    }
  }

  cout << answer << endl;
}
