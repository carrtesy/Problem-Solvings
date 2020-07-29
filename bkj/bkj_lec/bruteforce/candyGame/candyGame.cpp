#include <iostream>
#include <string>

using namespace std;

int horizon_check(char ** board, int N, int i, int j){
  char origin = board[i][j];

  int right = j+1;
  while(right < N){
    if(board[i][right] == origin){
      right++;
    } else {
      break;
    }
  }

  int left = j-1;
  while(left >= 0){
    if(board[i][left] == origin){
      left--;
    } else {
      break;
    }
  }
 
  return right-left-1;
}


int vertical_check(char ** board, int N, int i, int j){
  char origin = board[i][j];

  int up = i-1;
  while(up >= 0){
    if(board[up][j] == origin){
      up--;
    } else {
      break;
    }
  }

  int down= i+1;
  while(down < N){
    if(board[down][j] == origin){
      down++;
    } else {
      break;
    }
  }
 
  return down-up-1;
}

int rightflip(char ** board, int N, int i, int j){
  if(j >= N-1){
    return -1;
  }

  char tmp;
  tmp = board[i][j];
  board[i][j] = board[i][j+1];
  board[i][j+1] = tmp;

  int h1, h2, v1, v2;
  h1 = horizon_check(board, N, i, j);
  v1 = vertical_check(board, N, i, j); 
  h2 = h1;
  v2 = vertical_check(board, N, i, j+1);

  board[i][j+1] = board[i][j];
  board[i][j] = tmp;
  return max(max(h1, v1), max(h2, v2));
}

int leftflip(char ** board, int N, int i, int j){
  if(j <= 0){
    return -1;
  }

  char tmp;
  tmp = board[i][j];
  board[i][j] = board[i][j-1];
  board[i][j-1] = tmp;

  int h1, h2, v1, v2;
  h1 = horizon_check(board, N, i, j);
  v1 = vertical_check(board, N, i, j); 
  h2 = h1;
  v2 = vertical_check(board, N, i, j-1);

  board[i][j-1] = board[i][j];
  board[i][j] = tmp;
  return max(max(h1, v1), max(h2, v2));
}


int upflip(char ** board, int N, int i, int j){
  if(i <= 0){
    return -1;
  }

  char tmp;
  tmp = board[i][j];
  board[i][j] = board[i-1][j];
  board[i-1][j] = tmp;

  int h1, h2, v1, v2;
  h1 = horizon_check(board, N, i, j);
  v1 = vertical_check(board, N, i, j); 
  h2 = horizon_check(board, N, i-1, j);
  v2 = v1;

  board[i-1][j] = board[i][j];
  board[i][j] = tmp;

  return max(max(h1, v1), max(h2, v2));

}

int downflip(char ** board, int N, int i, int j){
  if(i >= N-1){
    return -1;
  }

  char tmp;
  tmp = board[i][j];
  board[i][j] = board[i+1][j];
  board[i+1][j] = tmp;

  int h1, h2, v1, v2;
  h1 = horizon_check(board, N, i, j);
  v1 = vertical_check(board, N, i, j); 
  h2 = horizon_check(board, N, i+1, j);
  v2 = v1;

  board[i+1][j] = board[i][j];
  board[i][j] = tmp;
  return max(max(h1, v1), max(h2, v2));
}

void printboard(char ** board, int N){
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cout << board[i][j];
    }
    cout << endl;
  }
}

int main(void){
  int N;
  char ** board;

  cin >> N;

  board = new char*[N];
  for(int i = 0; i < N; i++){
    board[i] = new char[N];
    string tmp;
    cin >> tmp;
    int j = 0;
    for(char& c: tmp){
      board[i][j++] = c;
    }
  }

  int ans = 0;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      int r, l, u, d;
      int m;
      r = rightflip(board, N, i, j);
      l = leftflip(board, N, i, j);
      u = upflip(board, N, i, j);
      d = downflip(board, N, i, j);
      m = max(max(r, l), max(u, d));
      if(m > ans){
        ans = m;
      }
    }
  }

  cout << ans << endl;

}
