#include <stdio.h>

int main(void)
{

	/*
		source: https://www.acmicpc.net/problem/1193
		author: Dongmin Kim(dongmin.kim.0220@gmail.com)

		bundle size is 
		1, 2, 3, 4, ...

		<bundles>
    1st: 1/1
    2nd: 1/2 2/1
    3rd: 3/1 2/2 1/3
    4th: 1/4 2/3 3/2 4/1
        ...
	
		n: input get
		pos: position of the bundle. 1st bundle? 2nd bundle? nth bundle?
		inc: increment of the bundle size
		flag: find if denominator is 1 or numerator is 1		

	*/

	int n;
	int pos, inc;
	int flag;

	pos = 1;
	inc = 1;
	flag = 0; // if bundle's den is 1 -> 1

	//1. get input
	scanf("%d", &n);

	//2. find apporpriate bundle	
	while (pos < n) {
		inc++;
		pos+=inc;
		flag = !flag;
	}
	
	//3. adjust fraction
	int den, num;

	den = flag? 1: inc;
	num = flag? inc: 1;
	

	for(int i = pos-inc+1; i < n; i++)
	{
		if(flag)
		{
			den++;
			num--;
		}
		else
		{
			den--;
			num++;
		}
	}
	
	printf("%d/%d\n", den, num); 
	
}
