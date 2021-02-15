#include <iostream>

using namespace std;

int main(void){
	int n;
	cin >> n;
	int* arr = new int[n];
	int* take = new int[n];
	int* ntake= new int[n];
	memset(take, 0, sizeof(int)*n);
	memset(ntake, 0, sizeof(int)*n);
	for(int i = 0; i < N; i++) cin >> arr[i];
	
	if(n == 1){
		cout << arr[0];
	}
	else if(n == 2){
		cout << arr[1];
	} else {
		take[0] = arr[0];
		take[1] = arr[0] + arr[1];
		ntake[1] = arr[0];

		for(int i = 2; i < n; i++){
			take[i] = max(ntake[i-1], ntake[i-2]) + arr[i];
			ntake[i] = take[n-1];
		}
		
		cout << max(take[n-1], ntake[n-1]);
	}
	delete arr, take, ntake;
	 
}
