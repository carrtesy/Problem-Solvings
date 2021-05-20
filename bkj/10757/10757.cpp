#include <cstdio>
using namespace std;
int main(void){
	char A[10002], B[10002], C[10003];
	scanf("%s %s", &A, &B);
	int aptr = 0, bptr = 0, cptr = 10001;
	while(A[aptr]) aptr++; aptr--;
	while(B[bptr]) bptr++; bptr--;
	C[10002] = '\0';
	
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
