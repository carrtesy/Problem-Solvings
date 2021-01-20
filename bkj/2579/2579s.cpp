#include <iostream>

using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int *step = new int[N+1];
    int *dp = new int[N+1];
    int max_point_0[310], max_point_1[310], max_point_2[310];

    
    for(int i = 1; i <= N; i++){
        cin >> step[i];
    }

    for(int i =1; i <= N; i++){
        max_point_1[i] = max(max_point_1[i-2], max_point_2[i-2]) + step[i];
        max_point_2[i] = max_point[i-1] + step[i];
    }
    
    cout << dp[N] << endl;
    delete arr, dp;
}
