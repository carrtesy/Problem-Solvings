/*
	source: https://www.acmicpc.net/problem/10951
	author: Dongmin Kim(dongmin.kim.0220@gmail.com)

*/

#include <stdio.h>

int main(void)
{
    int a, b;
		FILE * input;

		input = fopen("input.txt", "r");

    while(1)
    {
				do
				{	
        	a= fgetc(input);
				} while(!(48<=a && a<=57) && a != EOF);

				do
				{	
        	b= fgetc(input);
				} while(!(48<=b && b<=57) && b != EOF);
        
				
        if(a == EOF || b == EOF) break;

        printf("%d %d\n", a,b);
        


        a -= '0';
        b -= '0';
				printf("%d %d\n", a,b);
        
        printf("%d\n", a+b);
    }
    
}
