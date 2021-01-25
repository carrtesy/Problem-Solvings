#include <cstdio>
#include <cstring>
#define MOD 1000000007
#define INVALID -1

int n, h[10010];
int dp[10010][10010]; //[i][j] i번째 제단까지 진행을 했을 때 높이가 j인 경우의 수


int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &h[i]);
    }

    // 양쪽 끝 비교 0이 아니면 -> 0
    if(h[1] > 0 || h[n] > 0){
        printf("0");
        return 0;
    }

    // 가장 높은 높이 비교 -> 실패
    // memset(dp, 0xff, sizeof(dp)
    memset(dp, 0x00, sizeof(dp));
    dp[1][0] = 1;


    // i번째 제단에서 가능한 높이 경우의 수를 찾는다
    for(int i = 2; i <= n; i++){
        if(h[i] != -1){
            int j = h[i];
            if(j-1 >= 0){
                dp[i][j] += dp[i-1][j-1], dp[i][j] %= MOD;
            }
            dp[i][j] += dp[i-1][j], dp[i][j] %= MOD;
            if(j +1 <= 5000){
                dp[i][j] += dp[i-1][j+1], dp[i][j] %= MOD;
            }
        }
        else{
            for(int j = 0; j <= n/2; j++){
                // i 번째 제단이 j 의 높이를 갖는 경우의 수
                // j -> 이전의 높이가 j+1, j, j-1 합쳐지는 경우의 수
                if( j - 1 >= 0){
                    dp[i][j] += dp[i-1][j-1], dp[i][j] %= MOD;
                }
                dp[i][j] += dp[i-1][j], dp[i][j] %= MOD;
                if(j+1 <= 5000){
                    dp[i][j] += dp[i-1][j+1], dp[i][j] %= MOD;
                }
            }

        }
    }

    printf("%d", dp[n][0]);
}
