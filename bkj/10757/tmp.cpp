#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(void){
	
		srand(time(NULL));
	for(int t = 0; t < 1000000; t++){
		
		int _A = rand();
		int _B = rand();
		long long answer = _A + _B;
		
		char A[9], B[9], C[9];
		//scanf("%s %s", &A, &B);
		sprintf(A, "%d", _A);
		sprintf(B, "%d", _B);
		//printf("%s, %s\n", A, B);
		
		int aptr = 0, bptr = 0, cptr = 8;
		while(A[aptr]) aptr++; aptr--;
		while(B[bptr]) bptr++; bptr--;
		
		int carry = 0;
		while(aptr >= 0 || bptr >= 0){
			int a = aptr >= 0 ? A[aptr--] - '0': 0;
			int b = bptr >= 0 ? B[bptr--] - '0': 0;
			C[cptr--] = ((a + b + carry) % 10) + '0';
			carry = (a + b + carry) / 10;
		}
		
		if(carry){
			C[cptr] = '1';
		} else {
			cptr++;
		}
		
		//printf("%s\n", C+cptr);
		
		if( answer != atol(C+cptr)){
			printf("wrong! %d + %d = %lld // answer = %lld\n", _A, _B, _A + _B, atol(C+cptr));	
		}
	}
}
/*
int main(void){
	char A[10002], B[10002], C[10002];
	scanf("%s %s", &A, &B);
	int aptr = 0, bptr = 0, cptr = 10001;
	while(A[aptr]) aptr++; aptr--;
	while(B[bptr]) bptr++; bptr--;
	
	int carry = 0;
	while(aptr >= 0 || bptr >= 0){
		int a = aptr >= 0 ? A[aptr--] - '0': 0;
		int b = bptr >= 0 ? B[bptr--] - '0': 0;
		C[cptr--] = ((a + b + carry) % 10) + '0';
		carry = (a + b + carry) / 10;
	}
	
	if(carry){
		C[cptr] = '1';
	} else {
		cptr++;
	}
	
	printf("%s\n", C+cptr);
}
*/
