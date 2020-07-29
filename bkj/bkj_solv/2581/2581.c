/*
	source: https://www.acmicpc.net/problem/1193
	author: Dongmin Kim(dongmin.kim.0220@gmail.com)

*/

#include <stdio.h>
#include <math.h>


int isPrime(int n)
{
	
	if(n == 1) {
		return 0;
	} else if (n == 2 || n == 3){
		return 1;
	} else {
		
		int checkBdd = (int)ceil(sqrt((double)n));
		int flag = 1;
			 
		for (int i = 2; i <= checkBdd; i++)
		{
			if(n%i == 0){
				flag = 0;
				break;
			}
		}
	
		return flag;
	} 
}

int main(void)
{
	int M, N;
	int min;
	int sum = 0;
	int cnt = 0;

	scanf("%d %d", &M, &N);

	
	for(int i = M; i <= N; i++)
	{
		if(isPrime(i)){
			cnt += 1;
			if(cnt == 1) min = i;
			sum += i;
		} 
	}

	if(cnt == 0) printf("-1");
	else printf("%d\n%d\n", sum, min);
	

}
