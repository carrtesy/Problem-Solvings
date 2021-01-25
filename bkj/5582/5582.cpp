#include <cstdio>
#include <cstring>
using namespace std;

char str1[4010], str2[4010];
int len1, len2, ans, dp[4010][4010];

// lcs of strings ending with p1, p2
int calc(int p1, int p2){
    if(p1 < 0 || p2 < 0){
        return 0;
    }
    if(str1[p1] == str2[p2]){
        return calc(p1-1, p2-1) + 1;
    }
    else return 0;

}

int main(){
    scanf("%s", str1);
    scanf("%s", str2);
    len1 = strlen(str1);
    len2 = strlen(str2);

    for(int i = 0; i <= len1 - 1; i++){
        for(int j = 0; j <= len2 -1; j++){
            int tmp = calc(i, j);
            if(ans<tmp) ans = tmp;
        }
    }
    printf("%d", ans);
}
