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



    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end(), greater<>());

    ll result = 0;
    int ptA = 0;
    int ptB = 0;

    while(ptA < v1.size() && ptB < v2.size()){
        ll currentA = v1[ptA];
        ll target = T - currentA;
        if(v2[ptB] > target){
            ptB++;
        } else if(v2[ptB] == target){
            ll countA = 0;
            ll countB = 0;
            while(ptA < v1.size() && v1[ptA] == currentA){
                ptA++;
                countA++;
            }

            while(ptB < v2.size() && v2[ptB] == target){
                ptB++;
                countB++;
            }
            answer += (countA * countB);
        } else {
            ptA++;
        }

    }


    cout << answer << endl; 
   
}
