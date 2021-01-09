#include <iostream>

using namespace std;
int getStairNumCases(int digits, int max_digits, int front, int back){
  if(digits == max_digits){
    return 1;
  }

  int treecases = 0;

  // attach to front
  if(front != 1){
    treecases += getStairNumCases(digits + 1, max_digits, front - 1, back);
  }

  if(front != 9){
    treecases += getStairNumCases(digits + 1, max_digits, front + 1, back);
  }


  // attach to back
  if(back != 0){
    treecases += getStairNumCases(digits + 1, max_digits, front, back - 1);
  }

  if(back != 9){
    treecases += getStairNumCases(digits + 1, max_digits, front, back + 1);
  }

  return treecases;

}

int main(void){
  int N;
  cin >> N;

  int sum = 0;
  sum += getStairNumCases(1, N, 1, 1);
  sum += getStairNumCases(1, N, 2, 2);
  sum += getStairNumCases(1, N, 3, 3);
  sum += getStairNumCases(1, N, 4, 4);
  sum += getStairNumCases(1, N, 5, 5);
  sum += getStairNumCases(1, N, 6, 6);
  sum += getStairNumCases(1, N, 7, 7);
  sum += getStairNumCases(1, N, 8, 8);
  sum += getStairNumCases(1, N, 9, 9);

  cout << sum << endl;
}
