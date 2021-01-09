#include <iostream>

using namespace std;
int getgcd(int a, int b){
  int _a, _b;
  int na, nb;

  // ensure _a >= _b
  if(a < b){
    _a = b;
    _b = a;
  } else {
    _a = a;
    _b = b;
  }

  na = _b;
  nb = _a % _b;

  if(nb == 0){
    return _b;
  } else {
    return getgcd(na, nb);
  }

}

int getlcm(int a, int b){
  int gcd = getgcd(a, b);
  int ap = a / gcd;
  int bp = b / gcd;

  return gcd * ap * bp;
}

int main(void){
  int a, b;
  int gcd, lcm;

  cin >> a;
  cin >> b;

  cout << getgcd(a, b) << endl;
  cout << getlcm(a, b) << endl;
}
