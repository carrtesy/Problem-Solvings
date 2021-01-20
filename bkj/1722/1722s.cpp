#include <iostream>
#include <cstring>
#define ll long long

using namespace std;

ll factorial(int n, ll * memo){
    if(n <= 1){
        return 1;
    } else if(memo[n]){
        return memo[n];
    } else {
        return n * factorial(n-1, memo);
    }
}

ll query(int* arr, int idx, int N, ll start, ll end, ll* memo, int* ranks){
    cout << "start: " << start << " end: " << end << endl;
    if(start == end){
        return start;
    } else {
        ll chunk = factorial(N-1, memo);
        start += (ranks[arr[idx]] - 1) * chunk;
        end = start + chunk - 1;
        // update rank arr
        for(int i = arr[idx]; i < N; i++){
            if(!ranks[i]){
                continue;
            } else {
                ranks[i]--;
            }
        }
        ranks[arr[idx]] = 0;
        
        return query(arr, idx+1, N-1, start, end, memo, ranks);
    }
}

int main(void){
    int N, C;
    cin >> N >> C;

    int *nums = new int[N];
    bool *visited = new bool[N+1];
    memset(visited, 0, N+1);
    for(int i = 0; i < N; i++) cin >> nums[i];

    ll *factorials = new ll[N+1];    
 
    if(C == 1){
        ll target;
        cin >> target;
        char * s = new char[3*N];

        int idx = 0;
        for (int i = 0; i < N; i++){
            for(int j = 1; j < N; i++){
                if(visited[i] == true){
                    continue;
                }
                
                if(target > factorial(N-i-1, factorials)){
                    target -= factorial(N-i-1, factorials);
                } else {
                    s[idx++] = j + '0';
                    s[idx++] = ' ';
                    visited[j] = true;
                    break;
                }
            }
        }

    } else{
        ll result = 0;
        for(int i = 0; i < N; i++){
            for(int j = 1; j < nums[i]; j++){
                if(visited[j] == false){
                    result += factorial(N-i+1, factorials);
                }
            }
            visited[nums[i]] = true;
        }

        cout << result+1 << endl;
    }   
}
