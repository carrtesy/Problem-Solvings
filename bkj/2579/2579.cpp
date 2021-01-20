#include <iostream>

using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int *arr = new int[N+1];
    int *dp = new int[N+1];
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }

    dp[0] = 0;
    dp[1] = arr[1];
    int cnt = 1;
    for(int i = 2; i <= N; i++){

        if(cnt >= 2){
            dp[i] = dp[i-2] + arr[i];
            cnt = 1;
        } else {
            int e1, e2;
            e1 = dp[i-1];
            e2 = dp[i-2];

            if(e1 > e2){
                dp[i] = e1 + arr[i];
                cnt++;
            } else {
                dp[i] = e2 + arr[i];
                cnt = 1;
            }
        }
    }

    cout << dp[N] << endl;
    delete arr, dp;
}
