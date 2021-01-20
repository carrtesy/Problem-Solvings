#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;
int main(void){
    int T;
    int n, m;

    cin >> T;
    cin >> n;
    int * arr1 = new int[n];
    for(int i = 0; i < n; i++) cin >>arr1[i];
    
    cin >> m;
    int * arr2 = new int[m];
    for(int i = 0; i < m; i++) cin >>arr2[i];
    
    ll answer = 0;

    std::vector<ll> v1, v2;
 
    for(int r = 0; r < n; r++){
        ll tmp_sum = arr1[r];
        v1.push_back(tmp_sum);
        for(int c = r+1; c< n; c++){
            tmp_sum += arr1[c];
            v1.push_back(tmp_sum);
        }
    }
    
    for(int r = 0; r < m; r++){
        ll tmp_sum = arr2[r];
        v2.push_back(tmp_sum);
        for(int c = r+1; c< m; c++){
            tmp_sum += arr2[c];
            v2.push_back(tmp_sum);
        }
    }


    make_heap(v1.begin(), v1.end()); // max heap
    make_heap(v2.begin(), v2.end(), greater<>{}); // min heap

   
    while(v1.size() >= 1 && v2.size() >= 1){
        ll e1, e2, s;
        e1 = v1.front();
        e2 = v2.front();
        s = e1 + e2;
        if(s > T){
           pop_heap(v1.begin(), v1.end());
           v1.pop_back();
        } else if (s < T){
           pop_heap(v2.begin(), v2.end(), greater<>{}); // min heap
           v2.pop_back();
        } else {
           int v1cnt = 0, v2cnt = 0;
           while(v1.size() >= 1 && v1.front() == e1){
                pop_heap(v1.begin(), v1.end());
                v1.pop_back();
                v1cnt++;
           }
           
           while(v2.size() >= 1 && v2.front() == e2){
                pop_heap(v2.begin(), v2.end(), greater<>{}); // min heap
                v2.pop_back();
                v2cnt++;
           }
           answer += (v1cnt * v2cnt);
        }
    }

    cout << answer << endl; 
   
}
