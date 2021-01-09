#include <iostream>

using namespace std;
int main(void){
  int N;
  cin >> N;

  int *p = new int[N+1];
	p[0] = 0;
  cin >> p[1];
  for(int i = 2; i<=N; i++){
    int pi;
		int sum = 0;
    cin >> pi;
	
		for(int j = 1; j < i; j++){
			int sum_candidate = p[j] + p[i-j];
			if(sum_candidate > sum){
				sum = sum_candidate;
			}
		}

    p[i] = max(sum, pi);
  }

	cout << p[N] << endl;
  
}
