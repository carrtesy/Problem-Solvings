#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node{
  int num;
  int oken;
};

int main(void){
  int N;
  vector<node> v;

  // get input number
  cin>>N;

  // get inputs
  while(N--){
    node n;
    n.oken = -1;
    cin >> n.num;
    v.push_back(n);
  }


  // iterate
  for (vector<node>::reverse_iterator i = v.rbegin(); 
        i != v.rend(); i++) {
    for (vector<node>::reverse_iterator j = i;
        j != v.rend(); j++) {
      // same idx
      if(i == j){
        continue;
      }

      // overwrite if right is big
      if(i->num > j->num){
        j->oken = i->num;
      } else {
        break;
      }
    }
  }

  // result
  vector<node>::iterator it;
  for (it = v.begin();
      it != v.end(); it++){
    cout << it->oken << ' ';    
  }

}
