#include <iostream>
#include <cstring>

using namespace std;
int main(void){
	bool primes[1000001];
	int M, N;
	cin >> M;
	cin >> N;

	memset(primes, 1, sizeof(primes));

	primes[0] = false;
	primes[1] = false;
	for(int i = 2; i <= N; i++){
		if(primes[i] == true){
			if(i*i > N){
				break;
			}
			for(int j = i * i; j <= N; j += i){
				primes[j] = false;
			}
		}
	}

	for(int idx = M; idx <= N; idx++){
		if(primes[idx]){
			cout << idx << '\n';
		}
	}

  

}
