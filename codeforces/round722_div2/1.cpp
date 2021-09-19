#include <cstdio>
#include <vector>
using namespace std;

int main(void){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		int ans = 0;
		vector<int> a;
		
		int m = 101;
		int cnt = 0;
		
		for(int i = 0; i < n; i++){
			int e; scanf("%d", &e);
			if(e < m){
				cnt = 1;
				m = e;		
			} else if (e == m){
				cnt += 1;
			}
			a.push_back(e);
		}
		
		if (cnt != n){
			ans = n - cnt;
		} 
		
		printf("%d\n", ans);
	}
}
