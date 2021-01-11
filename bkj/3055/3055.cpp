#include <iostream>
#include <queue>
#include <utility>

using namespace std;
int main(void){
	int R, C;
	cin >> R >> C;
	char** map = new char*[R];
	queue<pair<int, int>> q;
	
	for(int i = 0; i < R; i++){
		string s;
		cin >> s;
		
		cout << s << endl;
		
		map[i] = new char[C];
		for(int j = 0; j < C; j++){
			map[i][j] = s[j];
		}
	}
	
	while(!queue.isEmpty()){
		
	}
	
	for(int i = 0; i < R; i++){
		delete map[i];
	}
	delete map;
}