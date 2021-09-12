#include <cstdio>

int getStrike(int a, int b){
	return (a/100 == b/100) + ((a%100)/10 == (b%100)/10) + ((a%10) == (b%10));
}

int getBall(int a, int b){
	int a1 = a/100, a2 = (a%100)/10, a3 = a%10;
	int b1 = b/100, b2 = (b%100)/10, b3 = b%10;
	int balls = 0;
	
	balls += ((a1 == b2) + (a1 == b3));
	balls += ((a2 == b1) + (a2 == b3));
	balls += ((a3 == b1) + (a3 == b2));
	return balls;
}

int main(void){
	int N;
	int answer = 0;
	scanf("%d", &N);
	bool arr[1000] = {};
	
	for(int i = 100; i < 1000; i++){
		int first = i / 100, second = (i%100)/10, third = i % 10;
		if(first == second || second == third || third == first){
			arr[i] = false;
		} else if (first == 0 || second == 0 || third ==0) {
			arr[i] = false;
 		} else {
		 	arr[i] = true;	
		}
	}

	while(N--){
		int guess, strike, ball;
		scanf("%d%d%d", &guess, &strike, &ball);
		for(int i = 100; i < 1000; i++){
			if(arr[i] == false) continue;
			if(strike != getStrike(i, guess) || ball != getBall(i, guess)) arr[i] = false;
		}
	}
	
	for(int i = 100; i < 1000; i++) if(arr[i]) answer ++;
	printf("%d\n", answer);
}
