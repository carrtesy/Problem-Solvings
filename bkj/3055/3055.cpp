#include <iostream>
#include <queue>
#include <utility>

using namespace std;

typedef struct _posinfo{
    int x;
    int y;
    int time; // -1 for *, and time for others
} posinfo;


void watermove(int posx, int posy, int R, int C, char **map, queue <posinfo> & q){
    int xStick[4] = {1, 0, -1, 0};
    int yStick[4] = {0, 1, 0, -1};
    for(int move = 0; move < 4; move++){
        int nextrow = posx + xStick[move];
        int nextcol = posy + yStick[move];
        bool rIsValid = (0 <= nextrow) && (nextrow < R);
        bool cIsValid = (0 <= nextcol) && (nextcol < C);
        if(rIsValid && cIsValid){
            if(map[nextrow][nextcol] == '.'){
                q.push(posinfo {nextrow, nextcol, -1});
                map[nextrow][nextcol] = '*';
            }
        }
    }
}

int main(void){
	int R, C;
	cin >> R >> C;
	char** map = new char*[R];
	queue <posinfo> q;
	
    int currow, curcol;
    int xStick[4] = {1, 0, -1, 0};
    int yStick[4] = {0, 1, 0, -1};
    bool escaped = false;
	
    for(int r = 0; r < R; r++){
		string s;
		cin >> s;
		map[r] = new char[C];
		for(int c = 0; c < C; c++){
			char status = s[c];
            map[r][c] = status;
            if(status == 'S'){
                currow = r;
                curcol = c;
            }
		}
	}

    // init queue

    // water pos
    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            if(map[r][c] == '*'){
                q.push(posinfo {r, c, -1});
            }
        }
    }

    // start pos
    q.push(posinfo {currow, curcol, 0});

	while(!q.empty()){
        // pop queue
        posinfo curPos = q.front();
        q.pop();
        currow = curPos.x;
        curcol = curPos.y;
        int t = curPos.time;
        char curStatus = map[currow][curcol];
    
        if(t == -1){
            // water
            watermove(currow, curcol, R, C, map, q);
            continue;
        }

        if(curStatus == 'D'){
            //check
            escaped = true;
            cout << t << endl;
            break;
        }
       
        // iterate
        // reachable?
        for(int move = 0; move < 4; move++){
            int nextrow = currow + xStick[move];
            int nextcol = curcol + yStick[move];
            bool rIsValid = (0 <= nextrow) && (nextrow < R);
            bool cIsValid = (0 <= nextcol) && (nextcol < C);

            if(rIsValid && cIsValid){
                char nextStatus = map[nextrow][nextcol];
                if(nextStatus != 'S' && nextStatus != '*' && nextStatus != 'X'){
                    q.push(posinfo {nextrow, nextcol, t+1});
                }
            }
        }

	}

    if(!escaped){
        cout << "KAKTUS" << endl;
    }
	
	for(int i = 0; i < R; i++){
		delete map[i];
	}
	delete map;
}
