#include <cstdio>
#include <iostream>

using namespace std;
int n, m, pr[1000010];

// a's parent
int findf(int a){
    if(a == pr[a]) return a;
    //return findf(p[a]); // recursive- timeout

    pr[a] = findf(pr[a]);
    return pr[a];
}

void unionf(int a, int b){
    a = findf(a);
    b = findf(b);
    pr[a] = b; 
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf("%d%d", &n, &m);



    for(int i = 0; i <=n; i++){
        pr[i] = i;
    }

    while(m-- > 0){
        int cmd, a, b;
        scanf("%d%d%d", &cmd, &a, &b);

        if(cmd == 0){
            //union
            unionf(a, b);
        } 

        else if(cmd == 1){
            //find
            int apar = findf(a);
            int bpar = findf(b);
            if(apar == bpar){
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }
}
