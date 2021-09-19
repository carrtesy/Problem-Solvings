#include <cstdio>

using namespace std;

int getScore(int a, int b){
	if (a == b){
		return a * 10;
	} else {
		return (a + b) % 10;
	}
}

int main(void){
	int A, B; scanf("%d %d", &A, &B);
	int my_score = getScore(A, B);
	int total_cases = 18 * 17 / 2;
	int better_cases = 0;

	if(A == B){
		better_cases = total_cases - (10 - A);
	} else {
		for(int a = 1; a <= 10; a++){
			for(int b = a + 1; b <= 10; b++){
				if(my_score > getScore(a, b)){
					if( a == A || a == B || b == A || b == B){
						better_cases += 2;
					}
					else {
						better_cases += 4;
					}	
				}
			}
		}	
	}
	
	printf("%.3f", float(better_cases)/float(total_cases));
}
