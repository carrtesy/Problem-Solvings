#include <iostream>

using namespace std;

int main(void){
  int N;
  cin >> N;


  int ** cost = new int* [N+1];

  // 0: R 1: G 2 : B
  cost[1] = new int[3];
  cin >> cost[1][0];
  cin >> cost[1][1];
  cin >> cost[1][2];

  // dynamic
  for(int i = 2; i <= N; i++){
    cost[i] = new int[3];
    int R, G, B;
    cin >> R >> G >> B;
    // ith man chooses R
    cost[i][0] = min(cost[i-1][1] + R, cost[i-1][2] + R);

    // ith man chooses G
    cost[i][1] = min(cost[i-1][0] + G, cost[i-1][2] + G);
    
    // ith man chooses B
    cost[i][2] = min(cost[i-1][0] + B, cost[i-1][1] + B);
  }

  // answer
  int min_cost = min(min(cost[N][0], cost[N][1]), cost[N][2]);
  cout << min_cost << endl;

  // delete
  for(int i = 1; i<= N; i++){
    delete cost[i];
  }
  delete cost;
}
