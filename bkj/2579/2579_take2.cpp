#include <cstdio>
#include <cstring>
#define max(a, b) ((a)>(b)?(a):(b))
using namespace std;

int main(void){
	int N; scanf("%d", &N);
	int* arr = new int[N+1]; arr[0] = 0;
	int* memo1 = new int[N+1]; memset(memo1, 0, sizeof(int)*(N+1));
	int* memo2 = new int[N+1]; memset(memo2, 0, sizeof(int)*(N+1));
	for(int i = 1; i <= N; i++) scanf("%d", &arr[i]);
	memo1[1] = arr[1];
	for(int i = 2; i <= N; i++){
		int score = arr[i];
		memo1[i] = max(memo1[i-2], memo2[i-2]) + score;
		memo2[i] = memo1[i-1] + score;
	}
	printf("%d\n", max(memo1[N], memo2[N]));
	delete arr, memo1, memo2;
}
