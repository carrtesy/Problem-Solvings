#include <iostream>
#include <cstring>
#define SEED 1000000000

using namespace std;

int main(void){
  int N;
  cin >> N;

 /*
     1 2 3 4 5 6 7 ... N
 0 | 0 
 1 | 1 
 2 | 1 
 3 | 1 
 4 | 1 
 5 | 1 
 6 | 1
 7 | 1 
 8 | 1
 9 | 1
 */
  long long stairnum[10][100+1];

  // first column
  stairnum[0][1] = 0;
  for (int i = 1; i < 10; i++){
    stairnum[i][1] = 1;
  }

  // iterate
  for (int j = 1; j < N; j++){
    stairnum[0][j+1] = stairnum[1][j]; 
    for (int i = 1; i < 9; i++){
      stairnum[i][j+1] = (stairnum[i-1][j] + stairnum[i+1][j]) % SEED;  
    }
    stairnum[9][j+1] = stairnum[8][j]; 
  }

  // get answer
  long long answer = 0;
  for(int i = 0; i < 10; i++){
    answer = (answer + stairnum[i][N]) % SEED;
  }

  cout << answer << endl;

  return 0;
}
