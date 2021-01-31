#include <iostream>
#include <string>

using namespace std;

bool isGenerator(int a, int b){
	// a generates b
	int _a = a;
	int generated_num = 0;
	while(_a){
		generated_num += _a % 10;
		_a = _a / 10;
	}
	
	generated_num += a;
	return generated_num == b;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;

	for(int i = 1; i <= N; i++){
		if(isGenerator(i, N)){
			cout << i << '\n';
			return 0;
		}
	}
	cout << 0 << '\n';
	return 0;	
}

