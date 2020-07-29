#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
#define MAX 10000

int main(void){

  int N;
  cin >> N;

  bool isPrime[MAX+1];
  vector<int> v;

  memset(isPrime, 1, sizeof(isPrime));

  isPrime[0] = false;
  isPrime[1] = false;

  for(int i = 2; i <= MAX; i++){
    if(i*i > MAX){
      break;
    }
    if(isPrime[i]){
      v.push_back(i);
      for(int j = i * i; j <= MAX; j += i ){
        isPrime[j] = false;
      }
    }
  }

  int vlen = v.size();
  while(N--){
    int n;
    int a;
    int b;
    int diff;
    bool init = false;
    cin >> n;

    for(int i = 0; i < vlen; i++){
      int _a, _b, _diff;
      _a = v[i];
      _b = n - _a;
      _diff = abs(_a - _b);
      
      if(!init && isPrime[_b]){
        a = _a;
        b = _b;
        diff = _diff;
        init = true;
        continue;
      }

      if(init && (_diff < diff) && isPrime[_b]) {
        a = _a;
        b = _b;
        diff = _diff;
      }
      
    }
    if(a>b){
      cout << b << ' ' << a << endl;
    } else {
      cout << a << ' ' << b << endl;
    }
  }

}
