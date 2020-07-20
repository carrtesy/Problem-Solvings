#include <iostream>
#include <string>
#include <stack>

using namespace std;
int main(void) {
  int N;
  
  cin >> N;
  cin.ignore();
  while(N--) {
    string str;
    stack <char> s;

    getline(cin, str);
    int flag = 1;
    for(char& c: str) {
      if(c == '(') {
        s.push(c);
      } else if(c == ')') {
        if(s.empty()){
          flag = 0;
          break;
        } else {
          s.pop();
        }
      } else if(c == '\n' || c == ' ') {
        continue;
      }
    }

    if(flag){
      if(!s.empty()){
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
      }
    } else {
      cout << "NO" << endl;
    }

  }

}
