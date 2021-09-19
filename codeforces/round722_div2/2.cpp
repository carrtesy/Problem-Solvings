#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int subseq(vector<int> arr, int index, vector<int> subarr, int max_len){
	if (index == arr.size()){
        int l = subarr.size();
  		if (l != 0 && l > max_len) {
			int _MAX = *max_element(subarr.begin(), subarr.end());
			for(int i = 0; i < l; i++){
				for(int j = i+1; j < l; j++){
					if (abs(subarr[i] - subarr[j]) < _MAX){
						return max_len;
					}
				}
			}
			return l;
		}
		return max_len;
    }
    else {
    	
    	if(max_len < subarr.size() + arr.size() - index - 1){
    		max_len = subseq(arr, index + 1, subarr, max_len);
			subarr.push_back(arr[index]);
			if(max_len < subarr.size() + arr.size() - index - 1){
				max_len = subseq(arr, index + 1, subarr, max_len);
			}
		}
        
        return max_len;
    }
}

int main(void){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		int ** arr = new *int[n];
		
		for (int i = 0; i < n; i++){
			arr[i] = new int[n];
		}
		
		vector <int> v;
		for(int i = 0; i < n; i++){
			int e; scanf("%d", &e);
			v.push_back(e);
		}
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				arr[i][j] = abs(v[i] - v[j]);
			}
		}
		
		for(int k = 0; k < n; k++){
			
		
		}
		
		
		printf("%d\n", ans);
	}
}
