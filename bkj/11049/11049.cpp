#include <iostream>
#include <cstdio>

struct Info{
    int r, c;
    Info(){}
};

int n, dp[510][510];
Info mat[510];

// s ~ e -> optimal value
int calc(int s, int e){
    if(e - s == 1){
        int result = mat[s].r * mat[s].c * mat[e].c;
        dp[s][e] = result;
        return result;
    }
    if ( e == s ){
        return 0;
    }   

    int mn = -1 ^ (1<<31);
    for (int mid = s; mid <= e-1; mid++){
        int front, back, subsol;
        if(dp[s][mid]){
            front = dp[s][mid];
        } else {
            front = calc(s, mid);
            dp[s][mid] = front;
        }

        if(dp[s][mid]){
            back = dp[mid+1][e];
        } else {
            back = calc(mid+1, e);
            dp[mid+1][e] = back;
        }

        subsol = front + back + mat[s].r * mat[mid].c * mat[e].c;
        mn = subsol < mn? subsol: mn;
    }
    dp[s][e] = mn;
    return mn;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &mat[i].r, &mat[i].c);
    }
    printf("%d", calc(1, n));
}
