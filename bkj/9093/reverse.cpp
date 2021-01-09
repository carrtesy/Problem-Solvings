#include <iostream>
#include <stack>
#include <sstream>
#include <string>

using namespace std;
int main(void){
  int T;
  stack <char> s;
  
  cin >> T;

  cin.ignore();
  while(T--){
    string str;
    getline(cin, str);
    istringstream ss(str);

    while(ss) {
      string word;
      ss>>word;

      for (char & c : word){
        s.push(c);
      }

      while(!s.empty()){
        if(s.top() != '\n'){
          cout << s.top();
        }
        s.pop();
      }
      if(ss){
        cout << ' ';
      }
    }
    cout << '\n';
  }
}
