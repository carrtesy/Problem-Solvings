#include <bits/stdc++.h>

using namespace std;

int getfix(bool** board, int i, int j){
    int whitestart_fix = 0;
    int blackstart_fix = 0;
    for(int r = 0; r < 8; r++){
        for(int c = 0; c < 8; c++){
            if(!(r % 2)){
                if(!(c % 2)){
                    whitestart_fix += board[r+i][c+j];
                    blackstart_fix += !board[r+i][c+j];
                } else {
                    whitestart_fix += !board[r+i][c+j];
                    blackstart_fix += board[r+i][c+j];
                } 
            } else {
                if(!(c % 2)){
                    whitestart_fix += !board[r+i][c+j];
                    blackstart_fix += board[r+i][c+j];
                } else {
                    whitestart_fix += board[r+i][c+j];
                    blackstart_fix += !board[r+i][c+j];
                }
            }
        }
    }
    return min(whitestart_fix, blackstart_fix);
}

int main(void){
    int N, M;
    cin >> N >> M;

    bool** board = new bool*[N]; 

    for(int r = 0; r < N; r++){
        board[r] = new bool[M];
        string s;
        cin >> s;
        for(int c = 0; c < M; c++){
            board[r][c] = (s[c] == 'B')? true: false;
        }
    }

    int minfix = -1 ^ (1 << 31);
    for(int i = 0; i + 8 <= N; i++){
        for(int j = 0; j + 8 <= M; j++){
            minfix = min(minfix, getfix(board, i, j));
        }
    }

    cout << minfix << endl;
    for(int r = 0; r < N; r++) delete board[r];
    delete board;
}
