#include <iostream>
#include <cstring>

using namespace std;
int main(void){
	
	// get inputs
	int T;
	int* inputs;
	int m = 0;
	cin >> T;
	inputs = new int[T];
	
	for(int t = 0; t < T; t++){
		cin >> inputs[t];
		if( inputs[t] > m ){
			m = inputs[t];
		}
	}
	
	// sieve of eratosthenes
	bool* isPrime = new bool[m+1];
	memset(isPrime, 1, m+1);
	
	// 4 <= m <= 10000
	isPrime[1] = false;
	for(int i = 2; i <= m ; i++){
		if (!isPrime[i]){
			continue;
		} 
		
		for(int j = i + i; j <= m; j+= i){
			isPrime[j] = false;
		}
	}
	
	for(int t = 0; t < T; t++){
		int n1, n2;
		int n = inputs[t];
		n1 = n2 = n / 2;
		while(n1 > 0 && n2 > 0){
			if (isPrime[n1] && isPrime[n2]){
				break;
			}
			n1--;
			n2++;
		}
		cout << n1 << ' ' << n2 << endl;
	}	
	
	delete isPrime;
}