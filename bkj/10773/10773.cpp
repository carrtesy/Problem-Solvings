#include <cstdio>
#include <stack>

using namespace std;
int main(void){
	int K;
	scanf("%d", &K);
	
	int sum = 0;
	stack<int> st;
	while(K--){
		int N;
		scanf("%d", &N);
		
		if(!N){
			sum -= st.top();
			st.pop();
		} else {
			sum += N;
			st.push(N);
		}
	}
	
	printf("%d", sum);	
}
