#include <iostream>

using namespace std;
int main(void){
/*
25C12

25 24 23 22 ... 14
--
12!

25!
----
12!*13!
*/

  int n, m;
  cin >> n;
  cin >> m;
  
  int num_2 = 0, num_5 = 0;
  int den_2 = 0, den_5 = 0;

	if(m == 0){
		cout << 0 << endl;
		return 1;
	}

  // num
  for(int i = n-m+1; i <= n; i++){
    int tmp = i;
    while(tmp % 2 == 0){
      num_2 += 1;
      tmp = tmp >> 1;
    }

    while(tmp % 5 == 0){
      num_5 += 1;
      tmp = tmp / 5;
    }
  }

  // den
  for(int i = 1; i <= m; i++){
    int tmp = i;
    while(tmp % 2 == 0){
      den_2 += 1;
      tmp = tmp >> 1;
    }

    while(tmp % 5 == 0){
      den_5 += 1;
      tmp = tmp / 5;
    }
  }

  int num, den;
  num = (num_2 > num_5) ? num_5: num_2;
  den = (den_2 > den_5) ? den_5: den_2;

  cout << num-den << endl;
}
