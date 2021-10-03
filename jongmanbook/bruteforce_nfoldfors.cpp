#include <iostream>
#include <vector>

int arr[6] = {11, 22, 33, 44, 55, 66};
int total_cnt = 0;

using namespace std;

void printPicked(vector<int> v){
	for(int i = 0; i < v.size(); i++){
		printf("%d ", arr[v[i]]);
	}
	printf("\n");
	return;
}

// pick m elements from n
void nCm(int n, vector<int> v, int m){
	
	if(m == 0) { printPicked(v); total_cnt++; return;}
	
	int start_point = v.empty() ? 0: v.back() + 1;
	
	for(int i = start_point; i < n ; i++){
		v.push_back(i);
		nCm(n, v, m-1);
		v.pop_back();
	}
}

int main(void){
	std::vector<int> v;
	nCm(6, v, 4);
	printf("total_cnt : %d\n", total_cnt);	
}
