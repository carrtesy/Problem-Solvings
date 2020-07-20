#include <iostream>
#include <cstring>
#include <vector>

#define MAX 1000000
using namespace std;
int main(void){
  bool isPrime[MAX+1];
  vector<int> primes;

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	

  memset(isPrime, 1, sizeof(isPrime));

  isPrime[0] = false;
  isPrime[1] = false;

  for(int i = 2; i <= MAX; i++){
    int is = i * i; // i squared
    if(is >= MAX){
      break;
    }
    if(isPrime[i]){
      primes.push_back(i);
      for(int j = is; j <= MAX; j += i){
        isPrime[j] = false;
      }
    }
  }

  int numprime = primes.size();
  while(1){
    int N;
    int a, b;
    cin >> N;

    if(!N) break;

    for(int i = 0; i < numprime; i++){
      a = primes[i];
      b = N - a;
      if(isPrime[b]){
        break;
      }
    }

    cout << N << " = " << a << " + " << b << endl;

  }

}
