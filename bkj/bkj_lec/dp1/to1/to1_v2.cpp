#include <iostream>
#include <cstring>
using namespace std;

int cntlogger(int N, int *ans, int cnt){

	int a = *ans;
	if(a==0 || a > cnt){
  	if(N % 3 == 0){
    	cntlogger(N/3, ans, cnt+1);
  	}
	}

	a = *ans;
	if(a==0 || a > cnt){
  	if(N % 2 == 0){
			cntlogger(N/2, ans, cnt+1);
		}
	}

	a = *ans;
	if(a==0 || a > cnt){  
  	if(N > 1){
			cntlogger(N-1, ans, cnt+1);
		}   
  }

	a = *ans;
  if (N == 1) {
		if(a == 0 || a > cnt){
			*ans = cnt;
		}
    return *ans;
  }
}

int cnt_till_to1(int N){
	if(N == 1){
		return 0;
	}

  int *ans = new int;
  *ans = 0;
	int a;
	a = cntlogger(N, ans, 0);
	delete ans;  
	return a;
}

int main(void){
  int N;
  cin >> N;

  cout << cnt_till_to1(N) << endl;
}
