#include <iostream>

#define MAX 1000000000
using namespace std;

int combination(int n, int r, int ** dp){
    // r == 0 , n == r -> 1
    if(r == 0 || n == r){
        return 1;
    } else if( dp[n][r] != 0){ 
        return dp[n][r];
    } else {
        return dp[n][r] = min(MAX, combination(n-1, r-1, dp) + combination(n-1, r, dp));
    }

}

void query(int n, int m, int k, char* s, int idx, int ** dp){
    // n == 0
    // m == 0
    // n+m C m

    if(n+m == 0){
        return;
    } else if(n == 0){
        s[idx] = 'z';
        query(n, m-1, k, s, idx+1, dp);
    } else if(m == 0){
        s[idx] = 'a';
        query(n-1, m, k, s, idx+1, dp);
    } else {
        int leftCount = combination( n + m - 1, m, dp);
        if(leftCount >= k){
            s[idx] = 'a';
            query(n-1, m, k, s, idx+1, dp);
        } else {
            s[idx] = 'z';
            query(n, m-1, k - leftCount, s, idx+1, dp);
        }
    }

}

int main(void){
    int N, M, K, L;
    cin >> N >> M >> K;

    L = N + M;
    // pascal triangle
    int ** dp = new int*[L+1];

    for(int n = 0; n <= L; n++){
        dp[n] = new int[L+1];
    }

    if(combination(L, M, dp) < K){
        cout << -1 << endl;
    } else {
        char * answer = new char[N+M];
        query(N, M, K, answer, 0, dp);
        cout << answer << endl;
    }
}   
