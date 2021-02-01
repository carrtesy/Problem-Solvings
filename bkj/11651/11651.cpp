#include <iostream>
#include <algorithm>

using namespace std;
struct coord {
	int x;
	int y;
};

bool cmp(coord a, coord b){
	if(a.y == b.y){
		return a.x < b.x;
	} else {
		return a.y < b.y;
	}
}

int main(void){
	int N;
	cin >> N;
	
	coord* arr = new coord[N];
	for(int i = 0; i < N; i++){
		int _x, _y;
		cin >> _x >> _y;
		arr[i] = {_x, _y};
	}
	
	sort(arr, arr+N, cmp);
	for(int i = 0; i < N; i++){
		printf("%d %d\n", arr[i].x, arr[i].y);
	}
}
