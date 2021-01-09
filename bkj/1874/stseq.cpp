#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main(void) {
  int N;
  stack <int> s;
  cin >> N;
  int max = N;
  int cur = 1;

  string answer = "";

  while(N--){
    int n;
    cin >> n;
    if(cur <= n) {
      for(; cur <= n; cur++) {
        s.push(cur);
        answer.push_back('+');
        answer.push_back('\n');
      }
    }

    if(s.top() == n) {
      s.pop();
      answer.push_back('-');
      answer.push_back('\n');
    } else {
      answer = "NO\n";
      break;
    }
  }

  cout << answer;
}
