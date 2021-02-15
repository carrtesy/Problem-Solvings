#include <iostream>
#include <cstring>
using namespace std;
int main(void){
	int N;
	cin >> N;
	int* arr= new int[N];
	int* dp = new int[N];
	int answer = 0;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
		dp[i] = 1;
		int maxlen = 0;
		for(int j = 0; j < i; j++){
			if(arr[i] > arr[j]) maxlen = max(maxlen, dp[j]);
		}
		dp[i] = maxlen + 1;
		if(dp[i] > answer) answer = dp[i];
	}
	cout << answer;
	delete arr, dp;
}
