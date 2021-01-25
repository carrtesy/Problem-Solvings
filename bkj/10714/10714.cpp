#include <iostream>
#include <cstring>
#define ll long long
using namespace std;

ll j_eat(int*, ll**, int, int, int);
ll i_eat(int*, ll**, int, int, int);

ll j_eat(int *cake, ll **dp, int N, int leftp, int rightp){
    if(leftp == rightp){
        return cake[leftp];
    }
    
    if(dp[leftp][rightp]){
        return dp[leftp][rightp];
    }
    
    ll c1, c2;
    c1 = cake[leftp] + i_eat(cake, dp, N, (leftp + 1 + N) % N, rightp);
    c2 = cake[rightp] + i_eat(cake, dp, N, leftp, (rightp - 1 + N) % N);
    return dp[leftp][rightp] = max(c1, c2);
}

ll i_eat(int *cake, ll **dp, int N, int leftp, int rightp){
    if(leftp == rightp){
        return 0;
    }

    if(cake[leftp] > cake[rightp]){
        return j_eat(cake, dp, N, (leftp + 1 + N) % N, rightp);
    } else{
        return j_eat(cake, dp, N, leftp, (rightp - 1 + N) % N);
    }
}

int main(void){
    int N;
    cin >> N;
    int *cake = new int[N];
    ll **dp = new ll*[N];
    for(int p = 0; p < N; p++){
        cin >> cake[p];
        dp[p] = new ll[N];
        memset(dp[p], 0, sizeof(ll) * N);
    }
    
    ll max_amt = 0;
    for(int p = 0; p < N; p++){
        max_amt = max(max_amt, cake[p]+ i_eat(cake, dp, N, (p + 1 + N) % N, (p - 1 + N) % N));
    }
    cout << max_amt << endl;
    delete cake;
    for(int p = 0; p < N; p++) delete dp[p];
    delete dp;
}
