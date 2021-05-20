#include <cstdio>

using namespace std;

int memo[102][102][102];

int w(int a, int b, int c){
	if(memo[a+50][b+50][c+50]){
		return memo[a+50][b+50][c+50];
	}
	
	if(a <= 0 || b <= 0 || c <= 0){
		return memo[a+50][b+50][c+50] = 1;
	}
	
	if(a > 20 || b > 20 || c > 20){
		return memo[a+50][b+50][c+50] = w(20, 20, 20);
	}
	
	if(a < b && b < c){
		return memo[a+50][b+50][c+50] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
	}
	
	return memo[a+50][b+50][c+50] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}

int main(void){
	while(1){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(a == -1 && b == -1 && c == -1){
			break;
		} else {
			printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));	
		}
	}
}
