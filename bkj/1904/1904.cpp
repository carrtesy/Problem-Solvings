#include <cstdio>

using namespace std;

int main(void){
	int N; scanf("%d", &N);	
	int dn = 1, dn_1 = 1;
	for(int i = 1; i < N; i++){
		int tmp = dn;
		dn = (dn + dn_1) % 15746;
		dn_1 = tmp;
	}
	printf("%d\n", dn);
}
