#include <iostream>
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

    int *arr = new int[N];
    for(int i = 0; i < N; i++) cin >> arr[i];

    ll *factorials = new ll[N+1];    
    int *ranks = new int[N+1];
    for(int i = 1; i <= N; i++) ranks[i] = i; 
 
    if(C == 1){

    } else{
        int answer = query(arr, 0, N, 1, factorial(N, factorials), factorials, ranks);
        cout << answer << endl;
    }   


}
