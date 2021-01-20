#include <iostream>
#define HASH 10007
using namespace std;
int main(void){
    int N, K;
    cin >> N >> K;

    int** dp = new int*[N+1];

    for(int n = 0; n <= N; n++){
        dp[n] = new int[n+1];
        dp[n][0] = 1;
    
        for(int k = 1; k < n; k++){
            dp[n][k] = (dp[n-1][k-1] + dp[n-1][k]) % HASH ;
        }

        dp[n][n] = 1;
    }

    cout << dp[N][K] << endl;   
}
