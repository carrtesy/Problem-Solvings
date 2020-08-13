#include <iostream>

using namespace std;
int main(void){
  int E, S, M;
  int e, s, m;
  int year = 1;
  e = 0;
  s = 0;
  m = 0;

  cin >> E;
  cin >> S;
  cin >> M;

  
  while(1){
    cout<< "(" << e+1 <<","<< s+1 <<"," <<m+1 <<")" <<endl;
    if(E == e+1 && S == s+1 && M == m+1){
      break;
    } else {
      e = (e + 1) % 15;
      s = (s + 1) % 28;
      m = (m + 1) % 19;
      year++;
    }
  }

  cout << year << endl;
}
