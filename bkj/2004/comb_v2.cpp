#include <iostream>

using namespace std;
int main(void){
  int n, m;
  int two = 0, five = 0;
  cin >> n >> m;

  for(long long i = 2; i <= n; i <<= 1){
    two += n/i;
  }

  for(long long i = 2; i <= n-m; i <<= 1){
    two -= (n-m)/i;
  }

  for(long long i = 2; i <= m; i <<= 1){
    two -= m/i;
  }

  for(long long i = 5; i <= n; i *= 5){
    five += n/i;
  }

  for(long long i = 5; i <= n-m; i *= 5){
    five -= (n-m)/i;
  }

  for(long long i = 5; i <= m; i *= 5){
    five -= m/i;
  }

  cout << min(two, five) << endl;
}
