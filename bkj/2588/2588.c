#include <stdio.h>
#include <math.h>

int main(void)
{
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	
	int sum, cur, div;
	int digit = 3;

	sum = 0;
	for (int i = 0; i < digit; i++){
		div = (int)pow(10, i);
		cur = (b/div) % 10;
		printf("%d\n", a * cur);
		
		sum += a * cur * (int)pow(10, i);
	}
	
	printf("%d\n", sum);

}
