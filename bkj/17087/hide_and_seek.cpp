#include <iostream>
#include <cmath>

using namespace std;
int GCD(int a, int b){
  if(b == 0){
    return a;
  } else {
    return GCD(b, a%b);
  }
}

int main(void){
  int N, S;

  cin >> N >> S;
  
  int *locations = new int[N];
  int *distance = new int[N];
  int gcd;

  cin >> locations[0];
  distance[0] = abs(locations[0] - S);
  gcd = distance[0];

  for(int i = 1; i < N; i++){
    cin >> locations[i];
    distance[i] = abs(locations[i] - S);
    gcd = GCD(gcd, distance[i]);
  }

  cout << gcd << endl;

}
