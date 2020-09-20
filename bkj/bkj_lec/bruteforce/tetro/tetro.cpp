#include <iostream>
#define CASES 2
using namespace std;

struct my_pair {
  int i;
  int j;
};

struct my_pair my_pair_add(struct my_pair p1, struct my_pair p2){
  struct my_pair result;
  result.i = p1.i + p2.i;
  result.j = p1.j + p2.j;
  return result;
}


bool is_layable(struct my_pair p, int N, int M){
  return p.i >= 0 && p.i < N && p.j >= 0 && p.j < M;
}

int get_sum(
  struct my_pair p1,
  struct my_pair p2,
  struct my_pair p3,
  struct my_pair p4,
  int N,
  int M,
  int ** board)
{
  bool layable =
  is_layable(p1, N, M) &&
  is_layable(p2, N, M) &&
  is_layable(p3, N, M) &&
  is_layable(p4, N, M);

  if(layable){
    int sum = 0;
    sum += board[p1.i][p1.j];
    sum += board[p2.i][p2.j];
    sum += board[p3.i][p3.j];
    sum += board[p4.i][p4.j];
    return sum;
  } else {
    return -1;
  }
}

int main(void){
  // get inputs
  int N, M;
  cin >> N >> M;
  int ** board = new int* [N];

  for(int i = 0; i < N; i++){
    board[i] = new int [M];
    for(int j = 0; j < M; j++){
      cin >> board[i][j];
      cout << board[i][j]; // check
    }
    cout << endl; // check
  }

  // calculate
  int max = -1;

  struct my_pair blocks[CASES][4] = {
    /*
      blue
    */
    {{0,0}, {0,1}, {0,2}, {0,3}},
    {{0,0}, {1,0}, {2,0}, {3,0}},

    /*
      yellow
    */
    {{0,0}, {0,1}, {1,0}, {1,1}},

    /*
      orange
    */
    {{0,0}, {1,0}, {2,0}, {2,1}},
    {{0,0}, {1,0}, {0,1}, {0,2}},
    {{0,0}, {0,1}, {1,1}, {1,2}},
    {{0,0}, {0,1}, {0,2}, {-1,2}},

    /*
      green
    */
    {{0,0}, {1,0}, {1,1}, {2,1}},
    {{0,0}, {1,0}, {1,-1}, {2,-1}},
    {{0,0}, {0,1}, {-1,1}, {-1,2}},
    {{0,0}, {0,1}, {1,1}, {1,2}},
    
    /*
      pink
    */
    {{0,0}, {1,0}, {2,0}, {1,1}},
    {{0,0}, {1,0}, {2,0}, {1,-1}},
    {{0,0}, {1,0}, {1,-1}, {1,2}},
    {{0,0}, {-1,0}, {1,0}, {0,1}},

  };

  for(int b = 0; b < CASES; b++){
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
        struct my_pair coord;
        coord.i = i;
        coord.j = j;

        int sum = get_sum(
          my_pair_add(coord, blocks[b][0]),
          my_pair_add(coord, blocks[b][1]),
          my_pair_add(coord, blocks[b][2]),
          my_pair_add(coord, blocks[b][3]),
          N,
          M,
          board
        );

        if(sum > max){
          max = sum;
        }
      }
    }
  }

  cout << max << endl;
  
  // delete
  for(int i = 0; i < N; i++){
    delete board[i];
  }
  delete board;

  return 0; 
}
