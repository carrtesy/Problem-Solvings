#include <cstdio>
#include <cstring>
using namespace std;

void fractal(int N, char** arr, int r, int c, bool cleanmode){
	if (cleanmode){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				arr[r+i][c+j] = ' ';
			}
		}
		return;
	}
	
	if(N == 3){
		arr[r+1][c+1] = ' ';
		return;
	}
	
	int _N = N/3;
	
	fractal(_N, arr, r, c, 0);
	fractal(_N, arr, r, c+_N, 0);
	fractal(_N, arr, r, c+2*_N, 0);
	fractal(_N, arr, r+_N, c, 0);
	fractal(_N, arr, r+_N, c+_N, 1);
	fractal(_N, arr, r+_N, c+2*_N, 0);
	fractal(_N, arr, r+2*_N, c, 0);
	fractal(_N, arr, r+2*_N, c+_N, 0);
	fractal(_N, arr, r+2*_N, c+2*_N, 0);
}

int main(void){
	int N;
	scanf("%d", &N);
	char ** arr = new char*[N];
	for(int i = 0; i < N; i++) {
		arr[i] = new char[N];
		for(int j = 0; j < N; j++){
			arr[i][j] = '*';
		}	
	}
	
	fractal(N, arr, 0, 0, 0);
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}
