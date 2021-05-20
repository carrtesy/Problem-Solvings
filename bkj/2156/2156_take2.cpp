#include <cstdio>
#include <iostream>
using namespace std;

int main(void){
	int N;
	scanf("%d", &N);
	int *wine = new int[N];
	for(int i = 0; i < N; i++) scanf("%d", &wine[i]);
	
	int answer;
	if(N == 1){
		answer = wine[0];
	} else if(N== 2){
		answer = wine[0] + wine[1];
	} else {
		// init
		int w0 = wine[0];
		int w1 = wine[1];
		int xx = 0, ox = w0, xo = w1, oo = w0 + w1;
		
		// loop
		for(int i = 2; i < N; i++){
			int w = wine[i];
			int xx_i_1 = xx;
			int xo_i_1 = xo;
			int ox_i_1 = ox;
			int oo_i_1 = oo;
			
			xx = max(ox_i_1, xx_i_1);
			ox = max(xo_i_1, oo_i_1);
			xo = max(xx_i_1, ox_i_1) + w;
			oo = xo_i_1 + w;
		}
		answer = max(max(xx, xo), max(ox, oo));
	}
	
	printf("%d\n", answer);
}
