#include <cstdio>
#include <iostream>
using namespace std;
int tt, n, card[1010];
int subsum[1010];
int k_dp[1010][1010], m_dp[1010][1010];


int getsum(int s, int e){
    return subsum[e] - subsum[s-1];
}

int k_play(int, int);
int m_play(int, int);

int k_play(int s, int e){
    if(s == e){
        return card[s];    
    }
    if(k_dp[s][e] != -1){
        return k_dp[s][e];
    }

    int left = 0, right = 0;
    left = card[s] + getsum(s+1, e) - m_play(s + 1, e);
    right = card[e] + getsum(s, e-1) - m_play(s, e - 1);

    k_dp[s][e] = max(left, right);
    return k_dp[s][e]; 
}

int m_play(int s, int e){
    if(s == e){
        return card[s];    
    }
    int left = 0, right = 0;
    left = card[s] + getsum(s+1, e) - k_play(s + 1, e);
    right = card[e] + getsum(s, e-1) - k_play(s, e-1);
    return max(left, right);
}

int main(){
    scanf("%d", &tt);
    for(int tc = 1; tc <= tt; tc++){
        
        scanf("%d", &n);
        subsum[tc] = subsum[tc-1] + 1;
    }
}
