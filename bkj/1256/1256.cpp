#include <iostream>

using namespace std;
int main(void){
    int N, M, K, L;
    cin >> N >> M >> K;

    L = N + M;
    // pascal triangle
    int ** dp = new int*[L+1];

    for(int n = 0; n <= L; n++){
        dp[n] = new int[L+1];
        dp[n][0] = 1;
        
        for(int k = 1; k < n; k++){
            int sum = dp[n-1][k] + dp[n-1][k-1];
            dp[n][k] = sum <= K ? sum : K+1;
        }

        dp[n][n] = 1; 
    }

    int start = 1, end = dp[L][M];
    int z_left = M;
    char *answer = new char[L];
    int idx = 0;

    if (K > end){
        cout << -1 << endl;
    } else { 
        while(start != end){
            int up = dp[--L][z_left];
            if(K <= start + up - 1 ){
                answer[idx++] = 'a';
                end = start + up -1;
            } else {
                answer[idx++] = 'z';
                start += up;
                z_left--;
            }
        }
        answer[idx] = z_left? 'z':'a';
        cout << answer << endl;
    }


}
