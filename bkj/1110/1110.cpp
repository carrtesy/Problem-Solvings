#include <iostream>

using namespace std;

int get_first_digit(int n){
  return n % 10;
}

int get_second_digit(int n){
  return n / 10;
}

int combine(int second, int first){
  return second * 10 + first;
}

int main(void){
  int N;
  cin >> N;
  int counter = 0;
  int n = N;
  // cout<<"start:" << n <<endl;
  while(1){
    int second = get_second_digit(n);
    int first = get_first_digit(n);

    n = combine(first, get_first_digit(second + first));
    counter++;
    //cout << n << endl;
    if(n == N){
      break;
    }
  }

  cout << counter << endl;
}


