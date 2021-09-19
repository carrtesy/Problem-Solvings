#include <cstdio>

int main(void){
	int t; scanf("%d", &t);
	while(t--){
		int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d);
		int w1 = a > b? a : b;
		int w2 = c > d? c : d;
		int r1 = a > b? b : a;
		int r2 = c > d? d : c;
		bool fair = (w1 >= r2) && (w2 >= r1);
		if(fair){
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}
