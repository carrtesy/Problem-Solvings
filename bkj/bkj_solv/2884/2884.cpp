#include <iostream>

using namespace std;

int main(void){
  int H, M;
  cin >> H >> M;

  if( M >= 45 ) {
    cout << H << " " << M - 45 << endl;
  } else {
    int new_M = 15 + M; // 60 + (M - 45);
    if ( H == 0 ) {
      H = 23;
    } else {
      H--;
    }
    cout << H << " " << new_M << endl;
  }
}
