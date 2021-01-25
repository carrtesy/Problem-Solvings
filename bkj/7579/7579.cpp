#include <iostream>
#include <vector>

int n, m, mem[110], cost[110], ans;
int dp[10001]; // cost i -> max memory
vector<int> selected[10001];

int main(void){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &mem[i]);
    }

    for(int i = 1; i <= n; i++){
        scanf("%d", &cost[i]);
    }

    for(int i = 0; i <= 10000; i++){
        //calc
        int max_mem = 0;
        for(int j = 0; j <= i/2; j++){
            int mem_to_delete = getmem(n-j);
            int tmp = dp[j] + mem[mem_to_delete];

        }
    }

    // check m above
    for(int i = 0; i <= 10000; i++){
        if(dp[i] >= m){
            ans = i;
            break;
        }
    }


    printf("%d", ans);
}
