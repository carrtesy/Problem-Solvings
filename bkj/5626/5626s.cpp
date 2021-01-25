#include <cstdio>
#include <cstring>
#define MOD 1000000007
#define INVALID -1

int n, h[10010];
int dp[2][5010], prev = 0, cur =1;

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
    dp[prev][0] = 1;


    for(int i = 2; i <= n; i++){
        //dp[cur][xxx]
        int st = 0, ed = n /2;
        // cur 메모리 초기화
        for(int j = 0; j <= 5000; j++){
            dp[cur][j] = 0;
        }

        if(h[i] != -1){
            st = h[i], ed = h[i];
        }

        for(int j = st; j <= ed; j++){
            if(j - 1 >= 0) {
                dp[cur][j] += dp[prev][j-1];
                dp[cur][j] %= MOD;
            }

            dp[cur][j] += dp[prev][j];
            dp[cur][j] %= MOD;

            if(j+1 <= 5000){
                dp[cur][j] += dp[prev][j+1];
                dp[cur][j] %= MOD;
            }
        }

        // 1 -> 0, 0->1 flip
        prev ^= 1; 
        cur ^= 1;
    }

    printf("%d", dp[prev][0]);
}
