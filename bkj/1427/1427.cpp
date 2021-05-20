#include <cstdio>

using namespace std;

int main(void){
	int N;
	int digits[10] = {0};
	scanf("%d", &N);
	while(N){
		digits[N%10]++;
		N = N/10;
	}
	int ptr = 9;
	for(int ptr = 9; ptr >= 0; ptr--){
		while(digits[ptr]--){
			printf("%d", ptr);
		}
	}
}
