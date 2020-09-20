#include <iostream>
#define DEBUG 0

using namespace std;


int main(void){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++){
    int M, N, x, y;
    cin >> M >> N >> x >> y;

    int cur_x = 1; 
    int cur_y = 1;
    int year = 1;

    while(1){
      if(DEBUG){
        cout << "year: " << year << " cur_x: "<< cur_x << " cur_y: " << cur_y << endl;
      }
      // check year
      if(cur_x == x && cur_y == y){
        cout << year << endl;
        break;
      }
      
      // exit
      if(cur_x == M && cur_y == N){
        cout << -1 << endl; 
        break;
      }

      // update year
      cur_x = cur_x < M ? cur_x + 1 : 1;
      cur_y = cur_y < N ? cur_y + 1 : 1;
      year++;
      
    }
  }
}
