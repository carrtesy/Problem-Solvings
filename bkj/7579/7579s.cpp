#include <iostream>
#include <vector>

int n, m, mem[110], cost[110], ans;
int dp[101][10001]; // [j][i] till j app >  cost i -> max memory

using namespace std;
int main(void){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &mem[i]);
    }

    for(int i = 1; i <= n; i++){
        scanf("%d", &cost[i]);
    }


    for(int j = 1; j <= n; j++){
        for(int i = 0; i <= 10000; i++){
            //calc
            // [j][i] : till j app > how much?
            // use jth app/ or not
            // dp[j][i] = max(dp[j-1][i], dp[j-1][i-cost[j]] + mem[j]);

            dp[j][i] = dp[j-1][i]; // not using jth app
            if( i  - cost[j] >= 0){
                dp[j][i] = max(dp[j][i], dp[j-1][i-cost[j]] + mem[j]);
            }
        }
    }

    // check m above
    for(int i = 0; i <= 10000; i++){
        if(dp[n][i] >= m){
            ans = i;
            break;
        }
    }


    printf("%d", ans);
}
