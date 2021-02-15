#include <cstdio>
#include <vector>
using namespace std;

struct dungchi{
	int w, h;
};

int main(void){
	int N;
	scanf("%d", &N);
	vector<dungchi> v;
	while(N--){
		int x, y;
		scanf("%d %d", &x, &y);
		v.push_back({x, y});
	}
	for(vector<dungchi>::iterator it1 = v.begin(); it1 != v.end(); it1++){
		dungchi d1 = *it1;
		int bigger = 0;
		for(vector<dungchi>::iterator it2 = v.begin(); it2 != v.end(); it2++){
			dungchi d2 = *it2;
			if(d1.w < d2.w && d1.h < d2.h){
				bigger++;
			}
		}
		printf("%d ", bigger+1);
	}
	printf("\n");
}
