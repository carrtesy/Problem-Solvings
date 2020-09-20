#include <iostream>
#include <cstring>
#define INT_MAX 2147483647

using namespace std;

int get_digit_count(int n){
  int divider = 10;
  int counter = 1; 

  while(n % divider != n){
    counter++;
    divider *= 10;
  }

  return counter;
}

bool available_channel(int channel, bool* remocon){
  bool is_available = true;  
 
  // exceptional case
  if(channel == 0){
    return remocon[0];
  }

  while(channel){
    int digit;
    digit = channel % 10;
    is_available &= remocon[digit];
    if(!is_available){
      break;
    }
    channel /= 10;
  }

  return is_available;
}

int main(void){
  int N; // channel to go
  int M; // # of malfunctioning
  int init = 100;

  // remote controller status
  bool *remocon = new bool[10];

  memset(remocon, 1, 10);
  
  cin >> N;
  cin >> M;

  // broken key
  for(int i = 0; i < M; i++){
    int broken_key; 
    cin >> broken_key;
    remocon[broken_key] = 0;
  }
  
  // case 1. start from init, and use only +, -.
  int answer1 = abs(N - init);
  cout << "answer 1 : " << answer1 <<endl;


  // case 2. start from lower channel, and go upward
  int answer2 = INT_MAX;
  for(int i = N; i >= 0; i--){
    if(available_channel(i, remocon)){
      answer2 = get_digit_count(i) + abs(N - i);
      break;
    }
  }

  cout << "answer 2 : " << answer2 <<endl;

  // case 3. start from upper channel, and go downward
  int answer3 = INT_MAX;
  for(int i = N; i <= 1000000; i++){
    if(available_channel(i, remocon)){
      answer3 = get_digit_count(i) + abs(N - i);
      break;
    }
  }
  cout << "answer 3 : " << answer3 <<endl;

  int answer = min(min(answer1, answer2), answer3);
  cout << answer << endl;
  delete remocon;
  
}
