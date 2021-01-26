#include <cstdio>
#include <iostream>

using namespace std;

int findf(int* pr, int a){
    if(pr[a] == a){
        return a;    
    }
    return pr[a] = findf(pr, pr[a]);
}

void unionf(int* pr, int a, int b){
    a = findf(pr, a);
    b = findf(pr, b);
    pr[a] = b;
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    int *pr = new int[N+1];
    for(int i = 0; i <= N; i++) pr[i] = i;

    while(M--){
        int command, a, b;
        cin >> command >> a >> b;
        if(command == 0){
            unionf(pr, a, b);
        } else {
            if(findf(pr, a) == findf(pr, b)){
                printf("%s\n", "YES"); 
            } else {
                printf("%s\n", "NO"); 
            }
        }
    }
}
