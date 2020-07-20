#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;
int main(void) {
  int N;
  stack<int> s;
  cin>>N;

  while(N--) {
   string command;
   cin >> command;
   //cout << command <<endl;
   if(command.compare("push") == 0) {
    string num;
    cin >> num;
    s.push(stoi(num));
   } else if(command.compare("pop") == 0) {
    if(!s.empty()){
      cout << s.top() << endl;
      s.pop();
    } else {
      cout << -1 << endl;
    }
   } else if(command.compare("size") == 0) {
    cout << s.size() << endl;
   } else if(command.compare("empty") == 0) {
    cout << s.empty() << endl;
   } else if(command.compare("top") == 0) {
    if(!s.empty()){
      cout << s.top() << endl;
    } else {
      cout << -1 << endl;
    }
   }
   
  }
}

  

