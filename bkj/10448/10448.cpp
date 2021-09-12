#include <cstdio>

int arr[45];

int main(void){
	
	for(int i = 1; i < 45; i++){
		arr[i] = i * (i+1) / 2;
	}
	
	int N; scanf("%d", &N);
	while(N--){
		int n; scanf("%d", &n);
		bool found = false;
		for(int i = 1; i < 45; i++){
			for(int j = 1; j < 45; j++){
				for(int k = 1; k < 45; k++){
					if (arr[i] + arr[j] + arr[k] == n) found = true;
				}
			}
		}
		if(found){
			printf("1\n");
		} else {
			printf("0\n");
		}
	}
}
