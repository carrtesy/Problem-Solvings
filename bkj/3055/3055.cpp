#include <iostream>
#include <queue>
#include <utility>

using namespace std;
int main(void){
	int R, C;
	cin >> R >> C;
	char** map = new char*[R];
	queue<pair<int, int>> q;
	
    int curi, curj;
	for(int i = 0; i < R; i++){
		string s;
		cin >> s;
		
		cout << s << endl;
		
		map[i] = new char[C];
		for(int j = 0; j < C; j++){
			map[i][j] = s[j];
            if(map[i][j] == 'S'){
                curi = i;
                curj = j;
            }
		}
	}
	
	while(!queue.isEmpty()){
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                char status = map[i][j];

                switch(status){
                    case '.':{
                        break;
                    }
                    case '*':{
                        break;
                    }
                    case 'D':{
                        break;
                    }
                    case 'S':{
                        break;
                    }
                }


            }        
        }

	}
	
	for(int i = 0; i < R; i++){
		delete map[i];
	}
	delete map;
}
