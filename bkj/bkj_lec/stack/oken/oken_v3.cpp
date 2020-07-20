#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int main(void){
  int N;
  vector<int> v;
  vector<int> ans;

  stack<int> s; // index
  int vlen;
  cin >> N;

  while(N--){
    int n;
    cin >> n;
    v.push_back(n);
		ans.push_back(-1);
  }

  vlen = v.size();

  for(int i = 0; i < vlen; i++){
		if(i == 0){
			s.push(i);
		} else if(!s.empty() && v[s.top()] < v[i]){
			while(!s.empty() && v[s.top()] < v[i]){
				ans[s.top()] = v[i];
				s.pop();
			}
			s.push(i);
		} else {
			s.push(i);
		}
  } 

	while(!s.empty()){
		ans[s.top()] = -1;
		s.pop();
	}

	for (vector<int>::iterator it = ans.begin();
			it != ans.end(); it++){
		cout << *it << ' ';
	}

}
