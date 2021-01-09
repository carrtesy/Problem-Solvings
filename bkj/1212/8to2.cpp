#include <iostream>
#include <string>

using namespace std;
int main(void){
  string N;
  cin >> N;

  int strlen = N.length();

  // front
  if(strlen = 1 && N[0] == '0'){
    cout << 0 << endl;
    return 0;
  } else {
    switch(N[0]){
      case '1':
        cout << "1";
        break;
      case '2':
        cout << "10";
        break;
      case '3':
        cout << "11";
        break;
      case '4':
        cout << "100";
        break;
      case '5':
        cout << "101";
        break;
      case '6':
        cout << "110";
        break;
      case '7':
        cout << "111";
        break;
    }
    
  }

  // rest
  for(int i = 1; i < strlen; i++){
    switch(N[i]){
      case '0':
        cout << "000";
        break;
      case '1':
        cout << "001";
        break;
      case '2':
        cout << "010";
        break;
      case '3':
        cout << "011";
        break;
      case '4':
        cout << "100";
        break;
      case '5':
        cout << "101";
        break;
      case '6':
        cout << "110";
        break;
      case '7':
        cout << "111";
        break;
    }
  }
}
