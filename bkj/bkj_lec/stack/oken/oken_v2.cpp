#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void){
  int N;
  vector<int> v;
  int i, j;

  // get input number
  cin>>N;

  // get inputs
  for(int i = 0; i < N; i++){
    int n;
    cin >> n;
    v.push_back(n);
  }

  // 9 5 4 8
  i = 0;
  j = 1;
  // iterate
  while(1){
    if(v[i] > v[j]){
      j++;
      if(j >= N) {
        i++;
        j = i + 1;
      }
    } else {
      cout << "setup: " << "( "<< i<<","<< j<< ")" << endl;
      for(; i<j; i++){
        v[i] = v[j];
      }
      j++;
    }
    if(i >= N-1 && j >= N){
      break;
    }
  }


  // result
  vector<int>::iterator it;
  for (it = v.begin();
      it != v.end(); it++){
    cout << *it << ' ';    
  }

}
