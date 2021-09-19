#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>

using namespace std;
int main(void){
	int t; scanf("%d", &t);
	while(t--){
		
		set <int> s;
		int n; scanf("%d", &n);
		
		for(int i = 0; i < n; i++){
			int bk; scanf("%d", &bk);
			s.insert(bk);
		}
		
		bool cant_be_nice = false;
		while(1){
			bool new_element_added = false;
			vector <int> new_elements;
			
			set<int>::iterator i, j;
			for(i = s.begin(); i != s.end(); ++i){
				for(j = s.begin(); j != s.end(); j++){
					int bi = *i;
					int bj = *j;
					if(bi != bj){
						int diff = abs(bi-bj);
						
						if(s.find(diff) == s.end()){
							new_element_added = true;
							new_elements.push_back(diff);
						}
					}
				}
			}
			
			int nsize = new_elements.size();
			for(int i = 0; i < nsize; i++){
				s.insert(new_elements[i]);
			}
			if (s.size() > 300) cant_be_nice = true;
			if (cant_be_nice || !new_element_added) break;
		}
		
		if(cant_be_nice){
			printf("NO\n");
		} else {
			printf("YES\n");
			printf("%d\n", s.size());
			set<int>::iterator it;
			for(it = s.begin(); it != s.end(); ++it){
				printf("%d ", *it);
			}
			printf("\n");
		}
	}
}
