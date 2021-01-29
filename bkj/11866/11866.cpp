#include <cstdio>
#include <queue>

using namespace std;
int main(void){
    int N, K;
    scanf("%d %d", &N, &K);

    int total = N;
    int cur = 1;
    queue <int> q;

    for(int i = 1; i <= N; i++) q.push(i);

    printf("<");
    while(1){
        if(q.size() == 1){
            printf("%d>", q.front());
            break;
        }

        for(int i = 0; i < K-1; i++){
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        printf("%d, ", q.front());
        q.pop();
    }
}
