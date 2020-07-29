#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
#define MAX 1000000

int main(void){

  bool isPrime[MAX+1];
  vector<int> v;

  for(int i = 2; i <= MAX; i++){
    if(isPrime[i] == false){
      v.push_back(i);
      for(int j = i + i; j <= MAX; j += i ){
        isPrime[j] = true;
      }
    }
  }

  int N;
  cin >> N;
  int vlen = v.size();
  while(N--){
    int n, a, b;
    cin >> n;
    int cnt = 0;
    for(int i = 0; i < vlen; i++){
      a = v[i];
      b = n - a;

      if(b >= 2 && a <= b){
        if(isPrime[b] == false){
          cnt++;
        }
      } else {
        break;
      }
    }

    cout << cnt << '\n';
  }

}
