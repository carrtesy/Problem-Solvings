#include <iostream>
#include <algorithm>

using namespace std;

struct info{
    int a;
    int b;  
    int c;
};

bool cmp(info n1, info n2){
    return n1.c < n2.c;
}


int findf(int* anc, int x){
    if(anc[x] == x){
        return x;
    }
    return anc[x] = findf(anc, anc[x]);
}

void unionf(int* anc, int x, int y){
    int _x = findf(anc, x);
    int _y = findf(anc, y);
    anc[_y] = anc[_x]; 
}

int main(void){
    int N, M;
    cin >> N >> M;
    int answer = 0;
 
    // sort according to cost
    info* costs = new info[M];
    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        costs[i] = {a, b, c};
    }
    sort(costs, costs+M, cmp);
 
    // union-find
    int* anc = new int[N+1];
    int edgecnt = 0; // till n-1
    for(int i = 1; i <= N; i++) anc[i] = i;

    for(int i = 0; i < M; i++){
        info k = costs[i];
        if(findf(anc, k.a) != findf(anc, k.b)){
            unionf(anc, k.a, k.b);
            answer += k.c;
            edgecnt++;
        }
        if(edgecnt == N-1){
            break;
        }
    }

    cout << answer << '\n';

    delete costs;
    delete anc;
}
