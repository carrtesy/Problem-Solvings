#include <cstdio>
using namespace std;
int main(void){
	int N; scanf("%d", &N);
	
	int div = 2;
	while(N > 1){
		while(N % div){
			div++;
		}
		N = N / div;
		printf("%d\n", div);
	}
}
