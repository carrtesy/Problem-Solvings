#include <iostream>
#include <cstdio>

using namespace std;

struct Info{
    int r, c;
    Info(){}
};

int n, dp[510][510];
Info mat[510];

// s ~ e -> optimal value
int calc(int s, int e){
    if(dp[s][e]){
        return dp[s][e];
    }

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
        int subsol = calc(s, mid) + calc(mid+1, e) + mat[s].r * mat[mid].c * mat[e].c;
        mn = subsol < mn? subsol: mn;
    }
    
    dp[s][e] = mn;
    return mn;
}

void sol2{
	int len;
	for(len = 2; len <= n; len++){
		for(int s = 1; s + len -1 <= n; s++){
			int e = s + len - 1;
			for(int mid = s; mid <= e-1; mid++){
				int tmp = dp[s][mid] + dp[mid+1][e] + mat[s].r * mat[mid].c * mat[e].c;
			}		
		}
	}
}

int main(){
	int n;
    scanf("%d", &n);
    int **dp = new int*[n];
    
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &mat[i].r, &mat[i].c);
    }
    printf("%d", calc(1, n));
}
