#include <iostream>
#include <array>
#include <stack>
#include <vector>

#define MAXSIZE 1000000
using namespace std;
int main(void){
  array<int, MAXSIZE> a;
  int N;
  vector<int> v;
  vector<int> ans;

  stack<int> s;
  cin >> N;

  for(int i = 0; i < MAXSIZE; i++){
    a[i] = 0;
  }

  while(N--){
    int i;
    cin >> i;
    v.push_back(i);
    a[i]++;
    ans.push_back(-1);
  }
  
  int vlen = v.size();
  for(int i = 0; i< vlen; i++){
    if( i == 0 ) {
      s.push(i);
    } else if(!s.empty() && a[v[s.top()]] < a[v[i]]) {
      while(!s.empty() && a[v[s.top()]] < a[v[i]]){
        ans[s.top()] = v[i];
        s.pop();
      }
      s.push(i);
    } else {
      s.push(i);
    }
  }

  while(!s.empty()){
    s.pop();
  }
 
  vector<int>::iterator it;
  for(it = ans.begin(); it != ans.end(); it++){
    cout << *it << " ";
  } 

}
