#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
struct info{
	int r, c;
	int time;
};

int main(void){
	// input
	int R, C; scanf("%d %d", &R, &C);
	char** map = new char*[R];
	bool** visited = new bool*[R];
	queue<info> wq; // water
	queue<info> rq; // route
	
	info dest;
	for(int r = 0; r < R; r++){
		map[r] = new char[C];
		visited[r] = new bool[C]; memset(visited[r], 0, sizeof(bool) * C);
		string s; cin >> s;
		for(int c = 0; c < C; c++){
			map[r][c] = s[c];
			if(map[r][c] == '*'){
				wq.push({r, c, 0});
			} else if(map[r][c] == 'S'){
				rq.push({r, c, 0});
			} else if(map[r][c] == 'D'){
				dest.r = r;
				dest.c = c;	
			}
		}
	}
	
	int t = 0;
	int rstick[4] = {1, -1, 0, 0};
	int cstick[4] = {0, 0, 1, -1};
	bool found = false;
	while(!rq.empty()){
		// water
		while(!wq.empty()){
			info water = wq.front();
			if(water.time > t){
				break;
			}
			wq.pop();
			for(int i = 0; i < 4; i++){
				int nr = water.r + rstick[i], nc = water.c + cstick[i];
				bool rIsValid, cIsValid;
				rIsValid = nr >= 0 && nr < R;
				cIsValid = nc >= 0 && nc < C;
				if(rIsValid && cIsValid){
					char nxt = map[nr][nc];
					if(nxt != 'D' && nxt != '*' && nxt != 'X'){
						map[nr][nc] = '*';
						wq.push({nr, nc, water.time+1});
					}
				}
			}
		}
		// find routes
		while(!rq.empty()){
			info route = rq.front();
			if(route.time > t){
				break;
			}
			rq.pop();
			
			visited[route.r][route.c] = true;
			if(route.r == dest.r && route.c == dest.c){
				found = true;
				break;
			}
			
			for(int i = 0; i < 4; i++){
				int nr = route.r + rstick[i], nc = route.c + cstick[i];
				bool rIsValid, cIsValid;
				rIsValid = nr >= 0 && nr < R;
				cIsValid = nc >= 0 && nc < C;
				if(rIsValid && cIsValid){
					char nxt = map[nr][nc];
					if(nxt != '*' && nxt != 'X' && !visited[nr][nc]){
						rq.push({nr, nc, route.time+1});
					}
				}
			}
		}
		
		if(found){
			break;
		}
		t++;
	}
	if(found){
		printf("%d\n", t);	
	} else {
		printf("KAKTUS\n");
	}
}
