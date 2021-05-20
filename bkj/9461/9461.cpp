#include <cstdio>

using namespace std;

int main(void){
	int T; scanf("%d", &T);
	long long arr[102] = {0};
	arr[1] = 1; arr[2] = 1; arr[3] = 1;
	arr[4] = 2; arr[5] = 2;
	for(int i = 6; i <= 100; i++){
		arr[i] = arr[i-5] + arr[i-1];
	}
	while(T--){
		int N; scanf("%d", &N);
		printf("%lld\n", arr[N]);
	}
}
